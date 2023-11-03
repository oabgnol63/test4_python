
import os

class Service:
	
	def __init__(self,id=000,name="Default Service",price=0.0):
		self._id = id
		self._name = name
		self._price = price
	
	def sin(self):
		self._id = input("Enter service's ID: ")
		self._name = input("Enter service's name: ")
		self._price = input("Enter service's fee: ")
		
	def get_id(self):
		return self._id
	
	def get_name(self):
		return self._name
	
	def get_fee(self):
		return self._price
	
	def sout(self):
		print("Sevice: " + self.get_name())
		print("Service ID: " + self.get_id())
		print("Service fee: " + self.get_fee())

class Person:

	def __init__(self,name="Default Person",addr="Default Address",tel="84010101010"):
		self._name = name
		self._addr = addr
		self._tel = tel

	def pin(self):
		self._name = input("Enter person's name: ")
		self._addr = input("Enter personal address: ")
		self._tel  = input("Enter contact number: ")
	
	def get_pname(self):
		return self._name

	def get_paddr(self):
		return self._addr
	
	def get_ptel(self):
		return self._tel
	
	def pout(self):
		print("Person's name: " + self._name)
		print("Personal Address: " + self._addr)
		print("Contact Number: " + self._tel)

class Customer(Person):

	def __init__(self,service_num=0):
		self._service_num = service_num
		self._services = []

	def cin(self):
		self.pin()
		self._service_num = int(input("Enter number of service(s): "))
		for i in range (0,self._service_num):
			new_service = Service()
			new_service.sin()
			self._services.append(new_service)
	
	def cout(self):
		os.system('clear')
		self.pout()
		print("List of service(s): ")
		for i in self._services:
			print("\t" + i.get_name() + " --- " + i.get_fee())

	def total_fee(self):
		self.cout()
		total = float(0)
		for i in self._services:
			total = total + float(i.get_fee())
		print("======>Total_fee: " + str(total) + "<======")
		print("-------------------------------------------")


