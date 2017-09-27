#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>

int main(){
  if(getuid()!=0){
		std::cout << "Welp, seems like you are not root." << std::endl;
		return 1;
	} else {
		std::cout << "Okay, you are root." << std::endl;
	}
	std::ofstream hostname_file;
	hostname_file.open("/etc/hostname");
	if(hostname_file.is_open()!=true){
		std::cout << "[ERROR] Cant open hostname file!" << std::endl;
		return 1;
	} else {
		std::cout << "Hostname file load complete." << std::endl;
	}
	hostname_file.close();
	std::cout << "Enter new hostname: ";
	std::string hostname_name;
	std::cin >> hostname_name;
	std::cout << "Are you sure about that? (y,n) ";
	std::string sure;
	std::cin >> sure;
	if(sure!="y"){
		std::cout << "Ok, stopping" << std::endl;
		return 0;
	}
	std::remove("/home/d3s/test.txt");
	hostname_file.open("/etc/hostname");
	hostname_file << hostname_name;
	hostname_file.close();
	std::cout << "Finished, you can reboot securely now." << std::endl;
	return 0;
}
