#include <iostream>
#include <stdio.h>

void apache2(void){
     system("sudo apt-get -y update");
     system("sudo apt-get install -y apache2");
     std::cout<<"Done! Apache2 was installed"<<std::endl;  
}

void mysql(void){
	system("sudo apt-get -y update");
	system("sudo apt-get install -y mysql-server mysql-client");
	std::cout<<"Done! Mysql was installed"<<std::endl;
}

void phpmyadmin(void){
	system("sudo apt-get -y update");
	system("sudo apt-get install -y phpmyadmin");
	std::cout<<"Done! Phpmyadmin was installed"<<std::endl;
}

void full(void){
	apache2();
	mysql();
	phpmyadmin();
	std::cout<<"Done! Full package was installed"<<std::endl;
}

void reinstall(int number){
	if(number == 3){
		system("sudo apt-get purge -y phpmyadmin");
		phpmyadmin();
		std::cout<<"Done! Phpmyadmin was reinstalled"<<std::endl;
	}
	else if(number == 2){
		system("sudo apt-get purge -y mysql-server mysql-client");
		mysql();
		std::cout<<"Done! Mysql was reinstalled"<<std::endl;
	}
	else if(number == 1){
		system("sudo apt-get purge -y apache2");
		apache2();
		std::cout<<"Done! Apache2 was reinstalled"<<std::endl;  
	}
	else if(number == 4){
		system("sudo apt-get purge -y apache2");
		system("sudo apt-get purge -y mysql-server mysql-client");
		system("sudo apt-get purge -y phpmyadmin");
		full();
		std::cout<<"Done! Full package was reinstalled"<<std::endl;
	}
	else{
		std::cout<<"Incorrect choice"<<std::endl;
	}
}

int main(void)
{
	int choose = 0;
	std::cout<<"Choose what you want install:\n";
	std::cout<<"If you want install:\n Apache2 - enter 1\n Mysql - enter 2\n Phpmyadmin - enter 3\n All package - enter 4\n";
	std::cout<<"If you want reinstall packages enter 5"<<std::endl;
    scanf("%d",&choose);
    if(choose == 1)
    	apache2();
    if(choose == 2)
    	mysql();
    if(choose == 3)
    	phpmyadmin();
    if(choose == 4)
    	full();
    if (choose == 5)
    {
    	choose == 0;
    	std::cout<<"Choose what you want reinstall:\n";
	    std::cout<<"If you want reinstall:\n Apache2 - enter 1\n Mysql - enter 2\n Phpmyadmin - enter 3\n All package - enter 4\n";
	    scanf("%d",&choose);
	    reinstall(choose);
    }
    std::cout<<"Done!"<<std::endl;
	return 0;
}