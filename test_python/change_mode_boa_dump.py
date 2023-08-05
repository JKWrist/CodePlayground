# coding:utf8

import logging
import os
import telnetlib
import time
from selenium import webdriver
from selenium.webdriver.common.by import By


#适配的测试项
#98D产品的web页面


class Webdriver():
    def __init__(self, url):
        self.driver = webdriver.Chrome()
        self.url = url

    # 登录web页面
    def dut_login(self, name, password):
        self.driver.get(self.url)
        time.sleep(1)
        self.driver.find_element(by=By.NAME, value="username").send_keys(name)
        time.sleep(1)
        self.driver.find_element(by=By.NAME, value="password").send_keys(password)
        time.sleep(1)
        self.driver.find_element(by=By.NAME, value="save").click()
        time.sleep(1)
        self.driver.maximize_window()
        time.sleep(1)

    # 在页面退出web页面的登录
    def dut_logout(self):
        self.driver.refresh()
        self.driver.find_element(By.XPATH, "//*[@id='header']/div/table/tbody/tr/td[3]/form/input[2]").click()
        time.sleep(1)
        self.driver.switch_to.alert.accept()
        time.sleep(1)

    # 在模式切换页面选择路由模式
    def dut_change_mode_to_router(self):
        self.driver.get(self.url)
        self.driver.find_element(By.LINK_TEXT, "工作模式").click()
        time.sleep(1)
        self.driver.switch_to.frame("contentIframe")
        time.sleep(1)
        self.driver.find_element(By.XPATH, "/html/body/div[2]/form/div[1]/table/tbody/tr/td/input[1]").click()
        time.sleep(1)
        self.driver.find_element(By.NAME, "save").click()
        time.sleep(30)

    # 在模式切换页面选择桥接模式
    def dut_change_mode_to_ap(self):
        self.driver.get(self.url)
        self.driver.find_element(By.LINK_TEXT, "工作模式").click()
        time.sleep(1)
        self.driver.switch_to.frame("contentIframe")
        time.sleep(1)
        self.driver.find_element(By.XPATH, "//html/body/div[2]/form/div[1]/table/tbody/tr/td/input[2]").click()
        time.sleep(1)
        self.driver.find_element(By.NAME, "save").click()
        time.sleep(30)

    # 退出驱动模式
    def dut_driverout(self):
        self.driver.quit()
        time.sleep(1)
class Test():
    def change_mode(self):
        for i in range(100000):
            web = Webdriver(url="http://192.168.10.1")
            web.dut_login("admin", "system")
            if 0 == i % 2:
                web.dut_change_mode_to_router()
            else:
                web.dut_change_mode_to_ap()
            web.dut_login("admin", "system")
            time.sleep(3)
            web.dut_logout()
            web.dut_driverout()
            print("测试次数：", i)

if __name__ == '__main__':
    test = Test()
    test.change_mode()
