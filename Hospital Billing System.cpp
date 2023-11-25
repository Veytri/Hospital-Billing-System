//Purpose of program: To calculate multiple patient's bill with multiple factors.
//Program name: Private hospital billing system.

#include<iostream>
#include<string>
using namespace std;

int days(string [], int, int);                 //function prototypes for functions that are to be used:
int hospital(string [], int [], int, int);
int surgery(string [], int, int);
int medication(string [], int, int);
int services(string [], int, int);
int total(int [], int);
int highest(int [], int);
int lowest(int [], int);

const int room1=800, room2=500, room3=350, room4=100, room5=600;   //constants global variable which values are fixed 
const int food1=90, food2=70, food3=50, food4=40, food5=80;        //constants global variable which values are fixed 
const int surgery1=600, surgery2=800, surgery3=350, surgery4=350, surgery5=1500;  //constants global variable which values are fixed 
const int med1=30, med2=90, med3=150, med4=15, med5=20;            //constants global variable which values are fixed 
const int service1=80, service2=140, service3=500, service4=200, service5=700;    //constants global variable which values are fixed 

//Group decision for rates, prices and options

// Room types : 1. Deluxe        800$ per day with 90$ charges of meal (3 times a day)
//              2. Twin sharing  500$ per day with 70$ charges of meal (3 times a day)
//              3. 4 bedded      350$ per day with 50$ charges of meal (3 times a day)
//              4. 6 bedded      100$ per day with 40$ charges of meal (3 times a day)
//              5. Delivery room 600$ per day with 80$ charges of meal (3 times a day)

// Pricing list: <<"1. Cesarean delivery "<<endl;        600$ per hour
// (Surgery)	 <<"2. Plastic "<<endl;                  800$ per hour
//				 <<"3. Thyroid "<<endl;                  350$ per hour
//		         <<"4. Cataract "<<endl;                 350$ per hour    
//		         <<"5. Spine "<<endl;                    1500$ per hour

// Pricing list: 	<<"1. Antibiotic "<<endl;       30$
// (Medication)	    <<"2. Local Anesthetic"<<endl;  90$
//	                <<"3. Strong Anesthetic"<<endl; 150$
//		            <<"4. Anti-Inflamatory"<<endl;  15$
//		            <<"5. Allergy"<<endl;           20$

// Pricing list: 	<<"1. X-ray "<<endl;             80$
// (Services)		<<"2. Blood Test "<<endl;        140$
//		            <<"3. DNA Test "<<endl;          500$
//		            <<"4. Physiotherapy "<<endl;     200$
//      		    <<"5. Rehabilitative "<<endl;    700$

int main()
{
	int SIZE;
	
	cout<<"How many patients are discharging today? "<<endl;     //user input for size of array
	cin>>SIZE;
	while(SIZE<=0){    
		cout<<"Error! Try again."<<endl    //error check
			<<"How many patients are discharging today? "<<endl;  
		cin>>SIZE;
	}
	
	string arrayName[SIZE];    //declare array
	
	for(int i=0; i<SIZE; i++){
		cout<<"Enter patient first name #"<<i+1<<" : "<<endl;    //inputing for array patient name
		cin>>arrayName[i];
	}
	
	int noofdays[SIZE];                           //array for number of days patient spent in hospital
	for(int i=0; i<SIZE; i++){
		noofdays[i]=days(arrayName, SIZE, i);     //call fucntion and assingning to the array
	}
	
	int hospitalStay[SIZE];                       //array for number of hospital stay cost
	for(int i=0; i<SIZE; i++){
		hospitalStay[i]=hospital(arrayName, noofdays, SIZE, i);      //call fucntion and assingning to the array
	}
	
	int surgeryCost[SIZE];                          //array for number of surgery cost
	for(int i=0; i<SIZE; i++){
		surgeryCost[i]=surgery(arrayName, SIZE, i);                 //call fucntion and assingning to the array
	}
	
	int medicationCost[SIZE];                       //array for number of medication cost
	for(int i=0; i<SIZE; i++){
		medicationCost[i]=medication(arrayName, SIZE, i);        //call fucntion and assingning to the array
	}
	
	int servicesCost[SIZE];                          //array for number of services cost
		for(int i=0; i<SIZE; i++){             
		servicesCost[i]=services(arrayName, SIZE, i);    //call fucntion and assingning to the array
	}
	
	int totalBill[SIZE];                          //array for total bill of each patient array
	for(int i=0; i<SIZE; i++){
		totalBill[i]=hospitalStay[i]+surgeryCost[i]+medicationCost[i]+servicesCost[i];	        //adding with using array and assigning into a seperate array	
	}
	
	for(int i=0; i<SIZE; i++){          //outputing information for every patient using array
		cout<<endl;
		cout<<"The bill for patient #"<<i+1<<" ("<<arrayName[i]<<") is:"<<endl;      
		cout<<"Hospital Stay: RM"<<hospitalStay[i]<<endl;          //output category price of each patient
		cout<<"Surgery Cost: RM"<<surgeryCost[i]<<endl;
		cout<<"Medication Cost: RM"<<medicationCost[i]<<endl;
		cout<<"Services Cost: RM"<<servicesCost[i]<<endl;
		cout<<"Total bill for this patient is: RM"<<totalBill[i]<<endl;   //output total price of each patient
	}
	
	int totalPatientBill=total(totalBill, SIZE);    //calling function for sum of charges
	cout<<endl;
	cout<<"Total charges for all patient: RM"<<totalPatientBill<<endl;    //output total price of all patient
	
	int totalCategoryHospitalStay=total(hospitalStay, SIZE);          //calling function for sum of category charges
	cout<<endl;
	cout<<"Total charges for category, hospital stay: RM"<<totalCategoryHospitalStay<<endl; //output of total price of a category
	
	int totalCategorySurgery=total(surgeryCost, SIZE);     //calling function for sum of category charges
	cout<<endl;
	cout<<"Total charges for category, surgery cost: RM"<<totalCategorySurgery<<endl; //output of total price of a category
	
	int totalCategoryMedication=total(medicationCost, SIZE); //calling function for sum of category charges
	cout<<endl;
	cout<<"Total charges for category, medication cost: RM"<<totalCategoryMedication<<endl; //output of total price of a category
	
	int totalCategoryServices=total(servicesCost, SIZE); //calling function for sum of category charges
	cout<<endl;
	cout<<"Total charges for category, services cost: RM"<<totalCategoryServices<<endl;  //output of total price of a category
	
	double sumofdays;     
	for(int i=0; i<SIZE; i++){     
		sumofdays=sumofdays+noofdays[i];     //summing all number of days for all patient
	}
	cout<<endl;
	cout<<"The average days spent for all patient is: "<<(sumofdays/SIZE)<<" days."<<endl; //outputing and calculating the average days spent in hospital for all patient
	
	int highestPayer=highest(totalBill, SIZE);   //calling function for highest paid charges of a patient
	cout<<endl;
	cout<<"The patient who is paying the highest bill is patient: "<<arrayName[highestPayer]<<endl;  //outputing name of patient of highest bill
	
	int lowestPayer=lowest(totalBill, SIZE);    //calling function for lowest paid charges of a patient
	cout<<"The patient who is paying the lowest bill is patient: "<<arrayName[lowestPayer]<<endl;      //outputing name of patient of lowest bill
	 
	return 0;
}

int days(string names [], int size, int i)  //function header for days spent in hospital
{
	int daysSpent; 
	
	cout<<endl; 
	cout<<"Patient #"<<i+1<<" : "<<names[i]<<endl;   
	cout<<"Number of days spent: ";        //request input from user
	cin>>daysSpent;
	while(daysSpent<=0){    
		cout<<"Error! Try again."<<endl    //error checker
			<<"Number of days spent: ";  
		cin>>daysSpent;
	}
	
	return daysSpent;	//return value and assigning it onto array in main funtion
}

int hospital(string names [], int daysSpent [], int size, int i) //function header for hospital stay cost
{
	int typeRoom;   //declaration
	int costHospital; 
	
	cout<<endl;
	cout<<"Patient #"<<i+1<<" : "<<names[i]<<endl;
	cout<<"Room Type"<<endl           //display choices and menu for user
		<<"--------------------"<<endl
		<<"1. Deluxe "<<endl
		<<"2. Twin sharing "<<endl
		<<"3. 4 bedded  "<<endl
		<<"4. 6 bedded "<<endl
		<<"5. Delivery room "<<endl
		<<"Enter the the type of room (number) "<<endl;   
	cin>>typeRoom;
	while(typeRoom<=0 || typeRoom>5){        
		cout<<"Error! Try again."<<endl        //error check for wrong choice
			<<"Enter the the type of room (number) "<<endl; 
		cin>>typeRoom;
	}
	if(typeRoom==1)     
		costHospital=(room1*daysSpent[i])+(food1*daysSpent[i]);  //calculation of hospital stay cost based on constant global variable
	else if(typeRoom==2)               
		costHospital=(room2*daysSpent[i])+(food2*daysSpent[i]);
	else if(typeRoom==3) 
		costHospital=(room3*daysSpent[i])+(food3*daysSpent[i]);
	else if(typeRoom==4) 
		costHospital=(room4*daysSpent[i])+(food4*daysSpent[i]);
	else if(typeRoom==5) 
		costHospital=(room5*daysSpent[i])+(food5*daysSpent[i]);	
	
	return costHospital; //return value and assigning it onto array in main funtion
}

int surgery(string names [], int size, int i)  //function header for surgery cost
{
	int typeSurgery, hoursSurgery;   //declaration
	int costSurgery;
	
	cout<<endl;
	cout<<"Patient #"<<i+1<<" : "<<names[i];      
	cout<<"\nSurgery Type"<<endl           //display choices and menu for user
		<<"--------------------"<<endl 
		<<"1. Cesarean delivery "<<endl
		<<"2. Plastic "<<endl
		<<"3. Thyroid "<<endl
		<<"4. Cataract "<<endl
		<<"5. Spine "<<endl
		<<"Enter the the type of surgery (number) "<<endl;  
	cin>>typeSurgery;
	while(typeSurgery<=0 || typeSurgery>5){   
		cout<<"Error! Try again."<<endl         //error check for wrong choice
			<<"Enter the the type of surgery (number) "<<endl;  
		cin>>typeSurgery; 
	}
	cout<<"Hours on surgery: ";  //get the hours from user
	cin>>hoursSurgery;
	while(hoursSurgery<=0){      
		cout<<"Error! Try again."<<endl  //error check for wrong input
			<<"Hours on surgery: ";   
		cin>>hoursSurgery;
	}
	if(typeSurgery==1)  
		costSurgery=surgery1*hoursSurgery;   //calculation of hospital stay cost based on constant global variable   
	else if(typeSurgery==2)
		costSurgery=surgery2*hoursSurgery;
	else if(typeSurgery==3) 
		costSurgery=surgery3*hoursSurgery;
	else if(typeSurgery==4) 
		costSurgery=surgery4*hoursSurgery;
	else if(typeSurgery==5) 
		costSurgery=surgery5*hoursSurgery;
		
	return costSurgery;    //return value and assigning it onto array in main funtion
	
}

int medication(string names[], int size, int i)  //function header for medication costs
{
	int typeMedication;   //declaration
	int costMedication;
	
	cout<<endl;
	cout<<"Patient #"<<i+1<<" : "<<names[i];
	cout<<"\nMedication Type"<<endl            //display choices and menu for user
		<<"--------------------"<<endl
		<<"1. Antibiotic "<<endl 
		<<"2. Local Anesthetic"<<endl
		<<"3. Strong Anesthetic"<<endl
		<<"4. Anti-Inflamatory"<<endl
		<<"5. Allergy"<<endl
		<<"Enter the the type of medication (number) "<<endl; 
	cin>>typeMedication;
	while(typeMedication<=0 || typeMedication>5){  
		cout<<"Error! Try again."<<endl              //error check
			<<"Enter the the type of medication (number) "<<endl;
		cin>>typeMedication;
	}
	if(typeMedication==1)         //calculation of hospital stay cost based on constant global variable
		costMedication=med1;                        
	else if(typeMedication==2)  
		costMedication=med2;
	else if(typeMedication==3) 
		costMedication=med3;
	else if(typeMedication==4) 
		costMedication=med4;
	else if(typeMedication==5) 
		costMedication=med5;
		
	return costMedication; //return value and assigning it onto array in main funtion
}

int services(string names [], int size, int i) //function header for services cost
{
	int typeServices; //declaration
	int costService=0;
	char addition;
	
	cout<<endl;
	cout<<"Patient #"<<i+1<<" : "<<names[i];
	cout<<"\nServices Types"<<endl        //display choices and menu for user
		<<"--------------------"<<endl
		<<"1. X-ray "<<endl
		<<"2. Blood Test "<<endl
		<<"3. DNA Test "<<endl
		<<"4. Physiotherapy "<<endl
		<<"5. Rehabilitative "<<endl
		<<"Enter the the type of services (number) "<<endl;
	cin>>typeServices;
	while(typeServices<=0 || typeServices>5){   
		cout<<"Error! Try again."<<endl       //error checker for wrong choice
			<<"Enter the the type of services (number) "<<endl;
		cin>>typeServices;
	}
	if(typeServices==1)                     //calculation of hospital stay cost based on constant global variable
		costService=costService+service1;          
	else if(typeServices==2)
		costService=costService+service2;
	else if(typeServices==3) 
		costService=costService+service3;	
	else if(typeServices==4) 
		costService=costService+service4;
	else if(typeServices==5) 
		costService=costService+service5;
		
	cout<<"Is there additional services? Type Y if Yes. Type other characters if No "<<endl;   //additional services choice
	cin>>addition;
	
	while(addition=='Y'){ 
		cout<<"Enter the the type of services (number) "<<endl; 
		cin>>typeServices;
		if(typeServices==1)                         //get total cost of additional servicies
			costService=costService+service1;       
		else if(typeServices==2)
			costService=costService+service2;
		else if(typeServices==3)
			costService=costService+service3;
		else if(typeServices==4)
			costService=costService+service4;
		else if(typeServices==5)
			costService=costService+service5;
		cout<<"Is there additional services? Type Y if Yes. Type other characters if No "<<endl; //request for additional services again
		cin>>addition;
	}
	
	return costService;	    //return value and assigning it onto array in main funtion
}

int total(int arrayCost [], int size)  //function header of total of category prices and total charges in main function
{
	int sum=0;
	
	for(int i=0; i<size; i++){
		sum=sum+arrayCost[i];    //sum counter of the total amount for an array
	}
	
	return sum;   
}

int highest(int arrayBill [], int size)    //function header to find highest payer
{
	int max=0;  //declaring by index of array
	
	for(int i=1; i<size; i++){
		if(arrayBill[max]<arrayBill[i])    //sorting the array for maximum in an array
			max=i;
	}
	
	return max;  //return index of max
}

int lowest(int arrayBill [], int size) //function header to find highest payer
{
	int min=0;  //declaring by index of array
	
	for(int i=1; i<size; i++){
		if(arrayBill[min]>arrayBill[i])     //sorting the array for minimum in an array
			min=i;
	}
	
	return min; //return index of min
}
