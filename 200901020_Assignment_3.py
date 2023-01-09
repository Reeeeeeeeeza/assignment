from xml.dom.minidom import parse
import xml.dom.minidom

docTree = xml.dom.minidom.parse('f.xml')
instance = docTree.documentElement
book = instance.getElementsByTagName("book")


import openpyxl
from openpyxl import Workbook
wb = Workbook()
excel = wb.active
i = int(2)

excel ['A' + str(1)] = ('ID')
excel ['B' + str(1)] = ('Author')
excel ['C' + str(1)] = ('Title')
excel ['D' + str(1)] = ('Genre')
excel ['E' + str(1)] = ('Price')
excel ['F' + str(1)] = ('Date of Publish')
excel ['G' + str(1)] = ('Description')

for books in book:
    excel['A' + str(i)] = (books.getAttribute('id'))

    excel['B'+str(i)] = (books.getElementsByTagName("author")[0].childNodes[0].data)

    excel['C'+str(i)] = (books.getElementsByTagName("title")[0].childNodes[0].data)

    excel['D'+str(i)] = (books.getElementsByTagName("genre")[0].childNodes[0].data)

    excel['E'+str(i)] = (books.getElementsByTagName("price")[0].childNodes[0].data)

    excel['F'+str(i)] = (books.getElementsByTagName("publish_date")[0].childNodes[0].data)

    excel['G'+str(i)] = (books.getElementsByTagName("description")[0].childNodes[0].data)

    i = i+1




wb.save("hamid.xlsx")