# coding:utf8
import datetime
import logging
import os
import telnetlib
import trio_websocket
from selenium import webdriver
import time
from selenium.webdriver.common import by
from selenium.webdriver.common.by import By


#适配的测试项
#98D产品的web页面


class Webdriver():
    # ssid定义为数字，类属性
    ssid = 123

    def __init__(self, url):
        self.driver = webdriver.Chrome()
        self.url = url

    # 登录web页面
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

    # 在页面进行设备重启
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
        Webdriver.ssid = Webdriver.ssid + 1
        print(Webdriver.ssid)
        return ssid

    # 在页面去开启telnet
    def dut_opentelnet(self):
        self.url1 = self.url + "/#/telnet/on"
        self.driver.get(self.url1)
        time.sleep(2)
        self.driver.switch_to.alert.accept()
        time.sleep(5)

    # 在页面退出web页面的登录
    def dut_logout(self):
        self.driver.refresh()
        self.driver.find_element(By.XPATH, "//*[@id='header']/div/table/tbody/tr/td[3]/form/input[2]").click()
        time.sleep(2)
        self.driver.switch_to.alert.accept()
        time.sleep(2)

    # 在页面重启设备
    def dut_reboot(self):
        self.driver.get(self.url)
        self.driver.find_element(By.LINK_TEXT, "系统管理").click()
        time.sleep(2)
        self.driver.switch_to.frame("contentIframe")
        self.driver.find_element(By.XPATH, "/html/body/form/div/table/tbody/tr/td/input").click()
        time.sleep(2)
        self.driver.switch_to.alert.accept()
        time.sleep(70)

    # 在模式切换页面选择路由模式
    def dut_change_mode_to_router(self):
        self.driver.get(self.url)
        self.driver.find_element(By.LINK_TEXT, "工作模式").click()
        time.sleep(2)
        self.driver.switch_to.frame("contentIframe")
        time.sleep(2)
        self.driver.find_element(By.XPATH, "/html/body/div[2]/form/div[1]/table/tbody/tr/td/input[1]").click()
        time.sleep(2)
        self.driver.find_element(By.NAME, "save").click()
        time.sleep(25)

    # 在模式切换页面选择桥接模式
    def dut_change_mode_to_ap(self):
        self.driver.get(self.url)
        self.driver.find_element(By.LINK_TEXT, "工作模式").click()
        time.sleep(2)
        self.driver.switch_to.frame("contentIframe")
        time.sleep(2)
        self.driver.find_element(By.XPATH, "//html/body/div[2]/form/div[1]/table/tbody/tr/td/input[2]").click()
        time.sleep(2)
        self.driver.find_element(By.NAME, "save").click()
        time.sleep(25)

    #在模式切换页面选择中继模式

    # 退出驱动模式
    def dut_driverout(self):
        self.driver.quit()
        time.sleep(2)

# 释放ip，重新获取Ip地址
class OS_opere():
    def check_wire(self):
        os.system("ipconfig/release")
        time.sleep(2)
        os.system("ipconfig/renew")
        time.sleep(2)
        r = os.popen("ping www.baidu.com")
        text = r.read()
        print(text)
        ele = 'TTL='
        if ele in text:
            print("切换模式后有线终端可以上网")
            return True
        else:
            print("切换模式后有线终端不能上网")
            return False


# Telnet登录设备
class TelnetClient():
    def __init__(self, ):
        self.tn = telnetlib.Telnet()

    # 此函数实现telnet登录主机
    def login_host(self, host_ip, username, password):
        try:
            # self.tn = telnetlib.Telnet(host_ip,port=23)
            self.tn.open(host_ip, port=2356)
        except:
            logging.warning('%s网络连接失败' % host_ip)
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
            logging.warning('%s登录成功' % host_ip)
            return True
        else:
            logging.warning('%s登录失败，用户名或密码错误' % host_ip)
            return False


    def  print_command(self, command):
        # 执行命令
        self.tn.write(command.encode('ascii') + b'\n')
        time.sleep(2)
        # 获取命令结果
        command_result = self.tn.read_very_eager().decode('ascii')
        time.sleep(3)
        print(str(command_result))
        return str(command_result)


    # 此函数实现执行传过来的命令，并输出其执行结果
    def execute_some_command(self, command):
        # 执行命令
        self.tn.write(command.encode('ascii') + b'\n')
        time.sleep(2)
        # 获取命令结果
        command_result = self.tn.read_very_eager().decode('ascii')
        time.sleep(3)
        logging.warning('命令执行结果：\n%s' % command_result)
        ele = " /bin/udhcpc -i "
        if ele in command_result:
            print("dhcpc进程已经起来了")
            return True
        else:
            print("dhcpc进程没有起来")
            return False
        # return command_result


    def check_ping_domain(self):
        command = 'ping baidu.com -c 5'
        # 执行命令
        self.tn.write(command.encode('ascii') + b'\n')
        time.sleep(3)
        # 获取命令结果
        command_result = self.tn.read_very_eager().decode('ascii')
        time.sleep(3)
        logging.warning('命令执行结果：\n%s' % command_result)
        ele = "ttl="
        if ele in command_result:
            print("可以ping通域名")
            return True
        else:
            print("不可以ping通域名")
            return False

    def check_ping_ip(self):
        command = 'ping 114.114.114.114 -c 5'
        # 执行命令
        self.tn.write(command.encode('ascii') + b'\n')
        time.sleep(4)
        # 获取命令结果
        command_result = self.tn.read_very_eager().decode('ascii')
        time.sleep(3)
        logging.warning('命令执行结果：\n%s' % command_result)
        ele = "ttl="
        if ele in command_result:
            print("可以ping通ip")
            return True
        else:
            print("不可以ping通ip")
            return False

    def check_dhcpc_state(self):
        command = 'ps |grep dhcpc'
        # 执行命令
        self.tn.write(command.encode('ascii') + b'\n')
        time.sleep(3)
        # 获取命令结果
        command_result = self.tn.read_very_eager().decode('ascii')
        time.sleep(3)
        logging.warning('命令执行结果：\n%s' % command_result)
        ele = "/bin/udhcpc -i nas0 -p /var/run/udhcpc.pid.nas0"
        if ele in command_result:
            print("dhcpc进程已经起来了")
            return True
        else:
            print("dhcpc进程没有起来")
            return False
        # return command_result
    def check_dns_state(self):
        command = 'ps |grep dns'
        # 执行命令
        self.tn.write(command.encode('ascii') + b'\n')
        time.sleep(3)
        # 获取命令结果
        command_result = self.tn.read_very_eager().decode('ascii')
        logging.warning('命令执行结果：\n%s' % command_result)
        time.sleep(3)
        ele = "/bin/dnsmasq -C /var/dnsmasq.conf -r /var/resolv.con"
        if ele in command_result:
            print("dnsmasq进程已经起来了")
            return True
        else:
            print("dnsmasq进程没有起来")
            return False
        # return command_result


    # 此函数实现执行传过来的命令，并输出其执行结果
    def check_internet(self):
        if self.check_ping_domain() == False:
            if self.check_dns_state() == False:
                if self.check_dhcpc_state() == False:
                    if self.check_ping_ip() == False:
                        return False
        else:
            return True

    # 退出telnet
    def logout_host(self):
        self.tn.write(b"exit\n")

class Write_data():

    def write_time(self):
        time = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        return str(time)

    def write_txt(self, txt):
        with open("D:\Python\98DE.txt", mode="a", encoding="utf-8") as file:
            file.write(self.write_time() + "\n" + "=========Start==============\n" + txt + "\n" + "=========END==========\n")

class Test():
    def test1(self):
        for i in range(5000):
            # 页面修改wifi配置，串口打开telnet,检查dhcpc进程
            # 页面重启设备，串口打开telnet，串口检查dhcpc进程
            web = Webdriver(url="http://cmcc.wifi/")
            web.dut_login("admin", "system")
            web.dut_opentelnet()
            web.dut_rebootwifi()
            telent = TelnetClient()
            telent.login_host("192.168.11.1", "admin", "s35t9752")
            sys1 = telent.execute_some_command("ps |grep dhcpc")
            if sys1 == False:
                print("======重启WIFI后，dhcpc进程不在，已复现问题======")
                break
            else:
                print("重启WIFI后，dhcpc进程仍在，未复现问题")
            web.dut_reboot()
            web.dut_login("admin", "system")
            web.dut_opentelnet()
            web.dut_logout()
            web.dut_driverout()
            telent.login_host("cmcc.wifi", "admin", "system")
            sys2 = telent.execute_some_command("ps |grep dhcpc")
            if sys2 == False:
                print("======重启设备后，dhcpc进程不在，已复现问题======")
                break
            else:
                print("重启设备后，dhcpc进程还在，未复现问题")
            print("测试次数：", i)
            web.dut_logout()

    def test_internet(self, username, passwd):
        for i in range(5000):
            # 页面修改wifi配置，串口打开telnet,检查dhcpc进程
            # 页面重启设备，串口打开telnet，串口检查dhcpc进程
            web = Webdriver(url="http://cmcc.wifi/")
            web.dut_login(username, passwd)
            if 0 == i % 2:
                web.dut_change_mode_to_router()
            else:
                web.dut_change_mode_to_ap()
            time.sleep(50)
            web.dut_login(username, passwd)
            web.dut_opentelnet()
            telent = TelnetClient()
            telent.login_host("cmcc.wifi", "admin", "system")
            sys1 = telent.execute_some_command("ps |grep dhcpc")
            if sys1 == False:
                print("======重启WIFI后，dhcpc进程不在，已复现问题======")
                break
            else:
                print("重启WIFI后，dhcpc进程仍在，未复现问题")
            # telent.logout_host()
            # web.dut_reboot()
            # web.dut_login("admin", "system")
            # web.dut_opentelnet()
            # web.dut_logout()
            # web.dut_driverout()
            # telent.login_host("cmcc.wifi", "admin", "system")
            sys2 = telent.execute_some_command("ps |grep dhcpc")
            if sys2 == False:
                print("======重启设备后，dhcpc进程不在，已复现问题======")
                break
            else:
                print("重启设备后，dhcpc进程还在，未复现问题")
            time.sleep(2)
            text1 = telent.print_command("iptables -t nat -vL")
            text2 = telent.print_command("iptables -t mangle -vL")
            text3 = telent.print_command("iptables -t raw -vL")
            Text = Write_data()
            Text.write_txt(text1)
            Text.write_txt(text2)
            Text.write_txt(text3)
            telent.logout_host()
            telent.login_host("cmcc.wifi", "admin", "system")
            web.dut_logout()
            web.dut_driverout()
            print("测试次数：", i)

if __name__ == '__main__':
    test = Test()
    test.test_internet("admin", "system")
    # test.test_internet("admin", "k635j295")