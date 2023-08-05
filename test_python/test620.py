import logging
import telnetlib

import trio_websocket
from selenium import webdriver
import time
from selenium.webdriver.common import by
from selenium.webdriver.common.by import By


class Webdriver():


    #ssid定义为数字
    ssid = 123
    def __init__(self, url):
        self.driver = webdriver.Chrome()
        self.url = url

    def dut_login(self, name, password):
        self.driver.get(self.url)
        time.sleep(2)
        self.driver.find_element(by=By.NAME, value="username").send_keys(name)
        time.sleep(2)
        self.driver.find_element(by=By.NAME, value="password").send_keys(password)
        time.sleep(2)
        self.driver.find_element(by=By.NAME, value="save").click()
        time.sleep(2)
        self.driver.maximize_window()
        time.sleep(5)
        # ele = self.driver.find_element(By.XPATH, "//*[@id='nav']/td[1]/a").text()
        # print(ele)
        # if ele =="快速设置":
        #     print("WEB页面登录成功")
        #     return True
        # else:
        #     print("WEB页面登录失败")
        #     return False

    #在页面进行设备重启
    def dut_rebootwifi(self):
        print("当前修改的WIFI参数：", Webdriver.ssid)
        ssid = str(Webdriver.ssid)
        self.driver.find_element(By.LINK_TEXT, "无线局域网").click()
        time.sleep(3)
        self.driver.switch_to.frame("contentIframe")
        time.sleep(2)
        self.driver.find_element(By.NAME, "ssid").clear()
        self.driver.find_element(By.NAME, "ssid").send_keys(ssid)
        time.sleep(5)
        self.driver.find_element(By.XPATH, "/html/body/form/div[2]/input[2]").click()
        time.sleep(20)
        Webdriver.ssid = Webdriver.ssid+1
        print(Webdriver.ssid)
        return ssid

    #在页面去开启telnet
    def dut_opentelnet(self):
        self.url1 = self.url+"/#/telnet/on"
        self.driver.get(self.url1)
        time.sleep(2)
        self.driver.switch_to.alert.accept()
        time.sleep(5)

    def dut_logout(self):
        self.driver.refresh()
        self.driver.find_element(By.XPATH, "//*[@id='header']/div/table/tbody/tr/td[3]/form/input[2]").click()
        time.sleep(2)
        self.driver.switch_to.alert.accept()
        time.sleep(2)

    def dut_reboot(self):
        self.driver.get(self.url)
        self.driver.find_element(By.LINK_TEXT, "系统管理").click()
        time.sleep(2)
        self.driver.switch_to.frame("contentIframe")
        self.driver.find_element(By.XPATH, "/html/body/form/div/table/tbody/tr/td/input").click()
        time.sleep(2)
        self.driver.switch_to.alert.accept()
        time.sleep(60)

    def dut_driverout(self):
        self.driver.quit()
        time.sleep(2)

class TelnetClient():
    def __init__(self,):
        self.tn = telnetlib.Telnet()

    # 此函数实现telnet登录主机
    def login_host(self, host_ip, username, password):
        try:
            # self.tn = telnetlib.Telnet(host_ip,port=23)
            self.tn.open(host_ip, port=2356)
        except:
            logging.warning('%s网络连接失败'%host_ip)
            return False
        # 等待login出现后输入用户名，最多等待10秒
        self.tn.read_until(b'login: ', timeout=10)
        self.tn.write(username.encode('ascii') + b'\n')
        # 等待Password出现后输入用户名，最多等待10秒
        self.tn.read_until(b'Password: ', timeout=10)
        self.tn.write(password.encode('ascii') + b'\n')
        # 延时两秒再收取返回结果，给服务端足够响应时间
        time.sleep(2)
        # 获取登录结果
        # read_very_eager()获取到的是的是上次获取之后本次获取之前的所有输出
        command_result = self.tn.read_very_eager().decode('ascii')
        # print(command_result)
        if 'Login incorrect' not in command_result:
            logging.warning('%s登录成功'%host_ip)
            return True
        else:
            logging.warning('%s登录失败，用户名或密码错误'%host_ip)
            return False

    # 此函数实现执行传过来的命令，并输出其执行结果
    def execute_some_command(self, command):
        # 执行命令
        self.tn.write(command.encode('ascii')+b'\n')
        time.sleep(2)
        # 获取命令结果
        command_result = self.tn.read_very_eager().decode('ascii')
        logging.warning('命令执行结果：\n%s' % command_result)
        ele = " /bin/udhcpc -i nas0 -p /var/run/udhcpc.pid.nas0"
        if ele in command_result:
            print("dhcpc进程已经起来了")
            return True
        else:
            print("dhcpc进程没有起来")
            return False
        # return command_result
    # 退出telnet

    def logout_host(self):
        self.tn.write(b"exit\n")

if __name__ == '__main__':
    for i in range(5000):
    #页面修改wifi配置，串口打开telnet,检查dhcpc进程
    #页面重启设备，串口打开telnet，串口检查dhcpc进程
        web = Webdriver(url="http://192.168.10.1")
        web.dut_login("admin", "system")
        web.dut_opentelnet()
        web.dut_rebootwifi()
        telent = TelnetClient()
        telent.login_host("192.168.10.1", "admin", "system")
        sys1 = telent.execute_some_command("ps |grep dhcpc")
        if sys1 ==False:
            print("======重启WIFI后，dhcpc进程不在，已复现问题======")
            break
        else:
            print("重启WIFI后，dhcpc进程仍在，未复现问题")
        web.dut_reboot()
        web.dut_login("admin", "system")
        web.dut_opentelnet()
        web.dut_logout()
        web.dut_driverout()
        telent.login_host("192.168.10.1", "admin", "system")
        sys2 = telent.execute_some_command("ps |grep dhcpc")
        if sys2 == False:
            print("======重启设备后，dhcpc进程不在，已复现问题======")
            break
        else:
            print("重启设备后，dhcpc进程还在，未复现问题")
        print("测试次数：", i)
