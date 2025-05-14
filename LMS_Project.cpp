#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

string check_id(string id,string pas);
int set_id(string id);
class user{
	public:
		string login_id,pass;
		string name;
		int status;
		string birth_date;
		string cnic;
		string ph_no;
		string city;
		
		user(){
		}
		void login(){
			cout<<"****Admin Data****"<<endl;
			cout<<"Enter your login ID:";
			string temp_id,temp_pass;
			while(1)
			{
				cin>>temp_id;
				if(temp_id==login_id)
				break;
				else{
				cout<<"Wrong Input.\nPlease enter ID again.";
				continue;
			}
			}
			cout<<"Password: ";
			while(1){
			cin>>temp_pass;
			if(temp_pass==pass)
			break;
			else{
				cout<<"Wrong Input.\nPlease enter password again.";
				continue;
			}
			
		}
		}
		void set_ad_data(){
			char ch;
			cout<<"Enter Admin Data:"<<endl;
			cout<<"Name: ";
			getline(cin,name);
			cin.sync();
			cout<<"CNIC: ";
			cin>>cnic;
			cout<<"City: ";
			cin>>city;
			cout<<"Phone Number: ";
			cin>>ph_no;
			cout<<endl<<"Enter your login ID: ";
			cin>>login_id;
			cout<<"Enter your password: ";
			cin>>pass;
			cout<<"Remember your ID and Password.\nDon't share it with anyone."<<endl;
			system("pause");
			system("CLS");
		}
		void set_fac_data(){
			cout<<"Enter New Faculty Member Data:"<<endl;
			cin.sync();
			cout<<"Name: ";
			getline(cin,name);
			cout<<"CNIC: ";
			cin>>cnic;
			cout<<"City: ";
			cin>>city;
			cout<<"Phone Number: ";
			cin>>ph_no;
			cout<<endl<<"Enter a valid ID for faculty Member: "<<endl;
			while(1)
			{
				cin>>login_id;
				int x;
				x=set_id(login_id);
				if(x==1)
				break;
				else
				cout<<"Given Login ID already exist.\nEnter another ID: ";
			}
			cout<<"Enter Password: ";
			cin>>pass;
			system("pause");
			system("CLS");
		}
		void set_std_data(){
			cout<<"Enter Student Data:"<<endl;
			cin.sync();
			cout<<"Name: ";
			getline(cin,name);
			cout<<"CNIC: ";
			cin>>cnic;
			cout<<"City: ";
			cin>>city;
			cout<<"Date of Birth: ";
			cin>>birth_date;
			cout<<"Press 1 if Student wants to be a hostel resident\nPress 2 if he wants to avail university transport"<<endl;
			cin>>status;
			cout<<endl<<"Assign a valid ID to Student: ";
			while(1)
			{
				cin>>login_id;
				int x;
				x=set_id(login_id);
				if(x==1)
				break;
				else
				cout<<"Given Login ID already exist.\nEnter another ID: ";
			}
			cout<<"Enter Password: ";
			cin>>pass;
			system("pause");
			system("CLS");
		}
};
class admin:public user{
	public:
		admin(){
		}
		string offer_course;
		int course_id;
		
};
class faculty:public admin{
	public:
		string course_fac_id;
		int cor_credit;
		int course_enroll[10];
		int Attend[10];
		int grades[10];
		int total_credit;
		string assess;
		int abs_marks;
		int marks;
		faculty(){
			
		}
};
class course:public faculty{
	protected:
	public:
		course(){
		}
		void course_offer(){
			cout<<"Enter a course information you want to offer:"<<endl;
			cin.sync();
			cout<<"Title: ";
			getline(cin,offer_course);
			cout<<"Course Code: ";
			cin>>course_id;
			cout<<"Course Credit Hours: ";
			cin>>cor_credit;
			cout<<"Assign Faculty Member"<<endl;;
			cout<<"Enter Faculty members ID:";
			while(1){
			cin>>course_fac_id;
			string x;
			x=check_id(course_fac_id,"00");
			if(x=="1")
			break;
			else
			cout<<"Wrong Id. Please Enter it again."<<endl;
		}
		}
		friend string check_id(string,string);
};
class student:public course{
	public:
	student(){
			course_enroll[10]={0};
			Attend[10]={2};
			grades[10]={0};
			total_credit=0;
		}
};
struct fac{
	faculty fac1;
	fac *nptr; 
};
fac *facfptr=NULL;
struct cors{
	course corse;
	cors *nptr;
};
cors *corsfptr=NULL;
struct stud{
	student student1;
	stud *nptr; 
};
stud *studfptr=NULL;
int set_id(string id){
	fac *faccurrentptr;
	stud *studcurrentptr;
	faccurrentptr=facfptr;
	while(faccurrentptr!=NULL)
	{
		if(faccurrentptr->fac1.login_id==id)
		return 0;
		faccurrentptr=faccurrentptr->nptr;
	}
	studcurrentptr=studfptr;
		while(studcurrentptr!=NULL)
		{
			if(studcurrentptr->student1.login_id==id)
			{
				return 0;
				break;
			}
			studcurrentptr=studcurrentptr->nptr;
	}
	return 1;
}
string check_id(string id,string pas){
	fac *faccurrentptr;
	stud *studcurrentptr;
	cors *corscurrentptr;
	if(pas=="00")
	{
	faccurrentptr=facfptr;
	while(faccurrentptr!=NULL)
	{
		if(faccurrentptr->fac1.login_id==id)
		return "1";
		faccurrentptr=faccurrentptr->nptr;
	}
	return "0";
}
	else
	if(pas=="11")
	{
		while(1)
		{
		int flag=0;
		cout<<"Enter your ID: ";
		cin>>id;
		cout<<"Enter Your Password: ";
		cin>>pas;
		faccurrentptr=facfptr;
		while(faccurrentptr!=NULL)
		{
			if(faccurrentptr->fac1.login_id==id&&faccurrentptr->fac1.pass==pas)
			{
			flag=1;
			break;
			}
			faccurrentptr=faccurrentptr->nptr;
	}
		if(flag==1){
		return faccurrentptr->fac1.login_id;
		break;
		}
		else
		cout<<"Wrong Input.Please enter it again."<<endl;
}
	}
	else
	{
		while(1)
		{
		int flag=0;
		cout<<"Enter your ID: ";
		cin>>id;
		cout<<"Enter Your Password: ";
		cin>>pas;
		studcurrentptr=studfptr;
		while(studcurrentptr!=NULL)
		{
			if(studcurrentptr->student1.login_id==id&&studcurrentptr->student1.pass==pas)
			{
				flag=1;
				break;
			}
			studcurrentptr=studcurrentptr->nptr;
	}
		if(flag==1){
		return studcurrentptr->student1.login_id;
		break;
		}
		else
		cout<<"Wrong Input.Please enter it again."<<endl;
}
	}
}
int main(){
	system("CLS");
	cout<<"          **************************************************"<<endl;
	cout<<"                 Welcome to Student Management System"<<endl;
	cout<<"          **************************************************"<<endl;
	admin adm1;
	adm1.set_ad_data();
	stud *studcurrentptr;
	stud *studptr;
	fac *faccurrentptr;
	fac *facptr;
	cors *corscurrentptr;
	cors *corsptr;
	int choice1,choice2;
	while(1){
		system("pause");
		system("CLS");
		cout<<"************Main Menu************"<<endl;
		cout<<"1.Admin"<<endl<<"2.Faculty Member"<<endl<<"3.Student"<<endl;
		cin>>choice1;
		system("CLS");
		switch(choice1)
		{
			case 1:
				adm1.login();
				while(1)
				{
					system("pause");
					system("CLS");
					cout<<"*****Sub Menu******"<<endl;
					cout<<"1.Offer Course"<<endl<<"2.Register New Student"<<endl<<"3.Add new Faculty Member"<<endl<<"4.Show All Faculty Members"<<endl<<"5.Return to main menu"<<endl;
					cin>>choice2;
					system("CLS");
					if(choice2==1)
					{
						if(facfptr==NULL)
						{
							cout<<"No Faculty Member is available for course."<<endl;
						}
						else
						{
							corsptr=new cors;
							corsptr->corse.course_offer();
							if(corsfptr==NULL)
							{
								corsfptr=corsptr;
								corsptr->nptr=NULL;
						}
						else
							{
								corscurrentptr=corsfptr;
								while(corscurrentptr->nptr!=NULL)
								{
									corscurrentptr=corscurrentptr->nptr;
							}
								corscurrentptr->nptr=corsptr;
								corsptr->nptr=NULL;
						}
						}
					}
					else
					if(choice2==2)
					{
						studptr=new stud;
						studptr->student1.set_std_data();
						if(studfptr==NULL)
						{
							studfptr=studptr;
							studptr->nptr=NULL;
						}
						else
						{
							studcurrentptr=studfptr;
							while(studcurrentptr->nptr!=NULL)
							{
								studcurrentptr=studcurrentptr->nptr;
							}
							studcurrentptr->nptr=studptr;
							studptr->nptr=NULL;
						}
					}
					else
					if(choice2==3)
					{
						facptr=new fac;
						facptr->fac1.set_fac_data();
						if(facfptr==NULL)
						{
							facfptr=facptr;
							facptr->nptr=NULL;
						}
						else
						{
							faccurrentptr=facfptr;
							while(faccurrentptr->nptr!=NULL)
							{
								faccurrentptr=faccurrentptr->nptr;
							}
							faccurrentptr->nptr=facptr;
							facptr->nptr=NULL;
						}
					}
					else
					if(choice2==4)
					{
						faccurrentptr=facfptr;
						while(faccurrentptr!=NULL)
						{
							cout<<"Name: "<<faccurrentptr->fac1.name<<endl;
							cout<<"Member ID: "<<faccurrentptr->fac1.login_id<<endl;
							faccurrentptr=faccurrentptr->nptr;
							cout<<"   ****"<<endl;
							}
					}
					else
					break;
				}
				break;
			case 2:
				if(facfptr==NULL){
					cout<<"No faculty member is registered yet."<<endl;
				}
				else
				{
					string id;
					id=check_id("11","11");
				while(1)
				{
					system("pause");
					system("CLS");
					cout<<"*****Sub Menu******"<<endl;
					cout<<"1.Assigned Courses"<<endl<<"2.Upload Attendence"<<endl<<"3.Generate Assessment"<<endl<<"4.Upload Grades"<<endl<<"5.Return to main menu"<<endl;
					cin>>choice2;
					system("CLS");
					if(choice2==1)
					{
						int flag=0;
						corscurrentptr=corsfptr;
						while(corscurrentptr!=NULL)
						{
							if(corscurrentptr->corse.course_fac_id==id)
							{
								cout<<"Title: "<<corscurrentptr->corse.offer_course<<endl;
								flag=1;
						}
							corscurrentptr=corscurrentptr->nptr;
							}
							if(flag==0)
							cout<<"No course has been assigned to you."<<endl;
					}
				else
					if(choice2==2)
					{
						int flag=0;
						int temp_code;
						corscurrentptr=corsfptr;
						while(corscurrentptr!=NULL)
						{
							if(corscurrentptr->corse.course_fac_id==id)
							{
								cout<<"Title: "<<corscurrentptr->corse.offer_course<<endl;
								cout<<"Course Code: "<<corscurrentptr->corse.course_id<<endl;
								flag=1;
						}
							corscurrentptr=corscurrentptr->nptr;
							}
						if(flag==1){
							cout<<"Please select from the above mentioned courses."<<endl;
							cout<<"Enter course ID\n";
							while(1)
							{
							int tflag=0;
							cin>>temp_code;
							corscurrentptr=corsfptr;
							while(corscurrentptr!=NULL)
							{
							if(corscurrentptr->corse.course_fac_id==id)
							{
								if(corscurrentptr->corse.course_id==temp_code)
								{
									tflag=1;
									break;
								}
						}
							corscurrentptr=corscurrentptr->nptr;
							}
							if(tflag==1)
							break;
							else
							cout<<"Wrong Input.Please enter it again:"<<endl;
							}
							int tflag=0;
							cout<<"Press 1 for present and 0 for absent against every enrolled student."<<endl;
							string ch_date;
							string slot;
							studcurrentptr=studfptr;
							while(studcurrentptr!=NULL)
							{
								for(int i=0;i<10;i++)
								{
									cout<<"Enter Date of attendence: ";
									cin>>ch_date;
									cout<<"Enter Slot: ";
									cin>>slot;
								if(studcurrentptr->student1.course_enroll[i]==temp_code)
								{
								tflag=1;
								cout<<studcurrentptr->student1.name<<": ";
								cin>>studcurrentptr->student1.Attend[i];
								break;
						}
						}
							studcurrentptr=studcurrentptr->nptr;
	}
						if(tflag==0)
						cout<<"No, Student enrolled in this course yet."<<endl;
						}
						else
						cout<<"No course has been assigned to you."<<endl;
				}
				else
					if(choice2==3)
					{
						int flag=0;
						int temp_code;
						corscurrentptr=corsfptr;
						while(corscurrentptr!=NULL)
						{
							if(corscurrentptr->corse.course_fac_id==id)
							{
								cout<<"Title: "<<corscurrentptr->corse.offer_course<<endl;
								cout<<"Course Code: "<<corscurrentptr->corse.course_id<<endl;
								flag=1;
						}
							corscurrentptr=corscurrentptr->nptr;
							}
						if(flag==1){
							cout<<"Please select from the above mentioned courses."<<endl;
							while(1)
							{
							int tflag=0;
							cin>>temp_code;
							corscurrentptr=corsfptr;
							while(corscurrentptr!=NULL)
							{
							if(corscurrentptr->corse.course_fac_id==id)
							{
								if(corscurrentptr->corse.course_id==temp_code)
								{
									tflag=1;
									break;
								}
						}
							corscurrentptr=corscurrentptr->nptr;
							}
							if(tflag==1)
							break;
							else
							cout<<"Wrong Input.Please enter it again:"<<endl;
							}
							cout<<"Enter assessment you want to generate: ";
							cin>>corscurrentptr->corse.assess;
							cout<<"Enter Total Marks: ";
							cin>>corscurrentptr->corse.marks;
							cout<<"Enter Absolute Marks: ";
							cin>>corscurrentptr->corse.abs_marks;
				}
			}
				else
					if(choice2==4)
					{
						int flag=0;
						int temp_code;
						corscurrentptr=corsfptr;
						while(corscurrentptr!=NULL)
						{
							if(corscurrentptr->corse.course_fac_id==id)
							{
								cout<<"Title: "<<corscurrentptr->corse.offer_course<<endl;
								cout<<"Course Code: "<<corscurrentptr->corse.course_id<<endl;
								flag=1;
						}
							corscurrentptr=corscurrentptr->nptr;
							}
						if(flag==1){
							cout<<"Please select from the above mentioned courses."<<endl;
							while(1)
							{
							int tflag=0;
							cin>>temp_code;
							corscurrentptr=corsfptr;
							while(corscurrentptr!=NULL)
							{
							if(corscurrentptr->corse.course_fac_id==id)
							{
								if(corscurrentptr->corse.course_id==temp_code)
								{
									tflag=1;
									break;
								}
						}
							corscurrentptr=corscurrentptr->nptr;
							}
							if(tflag==1)
							break;
							else
							cout<<"Wrong Input.Please enter it again:"<<endl;
							}
							int tflag=0;
							cout<<"Enter the marks against every enrolled student: "<<endl<<endl;
							studcurrentptr=studfptr;
							while(studcurrentptr!=NULL)
							{
								for(int i=0;i<10;i++)
								{
								if(studcurrentptr->student1.course_enroll[i]==temp_code)
								{
									tflag=1;
								cout<<studcurrentptr->student1.name<<": ";
								cin>>studcurrentptr->student1.grades[i];
								break;
						}
						}
							studcurrentptr=studcurrentptr->nptr;
	}
							if(tflag==0)
						cout<<"No, Student enrolled in this course yet."<<endl;
						}
						else
						cout<<"No course has been assigned to you."<<endl;
				}
					else
					break;
		}
	}
				break;
			case 3:
				if(studfptr==NULL){
					cout<<"No Student is registered yet."<<endl;
				}
				else
				{
					string id;
					id=check_id("22","22");
				while(1){
					system("pause");
					system("CLS");
					cout<<"*****Sub Menu******"<<endl;
					cout<<"1.Registered for course"<<endl<<"2.Generate Fee Challan"<<endl<<"3.View Attendence"<<endl<<"4.View Grades"<<endl<<"5.Return to main menu"<<endl;
					cin>>choice2;
					system("CLS");
					if(choice2==1)
					{
						if(corsfptr==NULL){
					cout<<"No Course is offered yet."<<endl;
				}
					else
					{
						int temp_code,flag=0;
						cout<<"Following courses are offered: "<<endl;
						corscurrentptr=corsfptr;
						while(corscurrentptr!=NULL)
						{
							cout<<"Title: "<<corscurrentptr->corse.offer_course<<endl;
							cout<<"Course Code: "<<corscurrentptr->corse.course_id<<endl;
							cout<<"Course Credits: "<<corscurrentptr->corse.cor_credit<<endl<<endl;
							corscurrentptr=corscurrentptr->nptr;
							}
						cout<<"Enter course code you want to take: ";
						while(1)
						{
							cin>>temp_code;
							corscurrentptr=corsfptr;
							while(corscurrentptr!=NULL)
							{
							if(corscurrentptr->corse.course_id==temp_code)
							{
								flag=1;
								break;
							}
							corscurrentptr=corscurrentptr->nptr;
							}
							if(flag==1)
							break;
							else
							cout<<"Wrong code.Please re-enter it:"<<endl;
						}
						studcurrentptr=studfptr;
						while(studcurrentptr!=NULL)
						{
							if(studcurrentptr->student1.login_id==id)
							break;
							studcurrentptr=studcurrentptr->nptr;
							}
						for(int i=0;i<10;i++)
						{
							if(studcurrentptr->student1.course_enroll[i]==0)
							{
								studcurrentptr->student1.course_enroll[i]=temp_code;
								studcurrentptr->student1.cor_credit=corscurrentptr->corse.cor_credit;
								studcurrentptr->student1.total_credit+=studcurrentptr->student1.cor_credit;
								cout<<"Course is registered successfully."<<endl;
								break;
							}
						}
					}
				}
				else
					if(choice2==2)
					{
					
						int fee;
						int h_charges=28000;
						int t_charges=15000;
						int m_charges=16000;
						int o_charges;
						int cr=2500;
						studcurrentptr=studfptr;
						while(studcurrentptr!=NULL)
						{
							if(studcurrentptr->student1.login_id==id)
							break;
							studcurrentptr=studcurrentptr->nptr;
							}
						if(studcurrentptr->student1.status==1){
						fee=cr*studcurrentptr->student1.total_credit+h_charges+m_charges;
						o_charges=h_charges+m_charges;
					}
						if(studcurrentptr->student1.status==2){
						fee=cr*studcurrentptr->student1.total_credit+t_charges+m_charges;
						o_charges=t_charges+m_charges;
				}
						cout<<"      Fee voucher"<<endl;
						cout<<"Askari Bank Limited"<<endl;
						cout<<"Name : "<<studcurrentptr->student1.name<<endl;
						cout<<"Registration No. : "<<studcurrentptr->student1.login_id<<endl;
						cout<<"Tuiton Fee: Rs."<<cr*studcurrentptr->student1.total_credit<<endl;
						cout<<"Other Charges: Rs."<<o_charges<<endl;
						cout<<endl<<"Total Fee : Rs."<<fee<<endl<<endl;
				}
				else
					if(choice2==3)
					{
						int i=0;
						int flag=0;
						int temp_code;
						studcurrentptr=studfptr;
						while(studcurrentptr!=NULL)
						{
							if(studcurrentptr->student1.login_id==id)
							break;
							studcurrentptr=studcurrentptr->nptr;
							}
						for(i=0;i<10;i++){
							corscurrentptr=corsfptr;
							while(corscurrentptr!=NULL)
							{
							if(corscurrentptr->corse.course_id==studcurrentptr->student1.course_enroll[i])
							{
								cout<<"Course Title: "<<corscurrentptr->corse.offer_course<<endl;
								cout<<"Course Code: "<<corscurrentptr->corse.course_id<<endl;
								flag=1;
							}
							corscurrentptr=corscurrentptr->nptr;
							}
						}
							if(flag==1){
								int tflag=0;
								cout<<"Enter your course code for which you want to see attendence: ";
							while(1)
								{
								cin>>temp_code;
							for(i=0;i<10;i++)
							{
							if(temp_code==studcurrentptr->student1.course_enroll[i])
							{
								tflag=1;
								break;
							}
							}
							if(tflag==1)
							break;
							else
							cout<<"Wrong Input.Please enter it again."<<endl;
						}
						cout<<"Name: "<<studcurrentptr->student1.name<<endl;
						cout<<"ID: "<<studcurrentptr->student1.login_id<<endl;
						cout<<"Course: "<<studcurrentptr->student1.course_enroll[i]<<endl;
						cout<<"Attendance :";
						if(studcurrentptr->student1.Attend[i]==1)
						cout<<"  Present"<<endl;
						else
						cout<<"  Absent"<<endl;
						}
						else
						cout<<"You are not enrolled in any course yet."<<endl;
				}
				else	
					if(choice2==4)
					{
						int i=0;
						int flag=0;
						int temp_code;
						studcurrentptr=studfptr;
						while(studcurrentptr!=NULL)
						{
							if(studcurrentptr->student1.login_id==id)
							break;
							studcurrentptr=studcurrentptr->nptr;
							}
						for(i=0;i<10;i++){
							corscurrentptr=corsfptr;
							while(corscurrentptr!=NULL)
							{
							if(corscurrentptr->corse.course_id==studcurrentptr->student1.course_enroll[i])
							{
								cout<<"Course Title: "<<corscurrentptr->corse.offer_course<<endl;
								cout<<"Course Code: "<<corscurrentptr->corse.course_id<<endl;
								flag=1;
							}
							corscurrentptr=corscurrentptr->nptr;
							}
						}
							if(flag==1){
								int tflag=0;
								cout<<"Enter your course code for which you want to see attendence: ";
							while(1)
								{
								cin>>temp_code;
							for(i=0;i<10;i++)
							{
							if(temp_code==studcurrentptr->student1.course_enroll[i])
							{
								tflag=1;
								break;
							}
							}
							if(tflag==1)
							break;
							else
							cout<<"Wrong Input.Please enter it again."<<endl;
						}
						cout<<"Name: "<<studcurrentptr->student1.name<<endl;
						cout<<"ID: "<<studcurrentptr->student1.login_id<<endl;
						cout<<"Course: "<<studcurrentptr->student1.course_enroll[i]<<endl;
						cout<<"Grades: "<<studcurrentptr->student1.grades[i]<<endl;
						}
						else
						cout<<"You are not enrolled in any course yet."<<endl;
				}	
					else
					break;
				}
			}
					break;
			default:
				cout<<"Wrong Input."<<endl;
		}
	}

}
