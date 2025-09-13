//This program obtains a list of names of students along with their grades. It will alphabetically sort the names, sort the grades
//and help the user find the grades of a student.
//Programmer: Maria Psomas
#include <iostream>
#include <iomanip>
#include <string.h>//For this program, I will be using C-string
using namespace std;
//First is the function to alphabetize the data.
void bubblesort_names (char *n[],int size,int g[])
{
	int i,j;
	for (j=1;j<size-1;j++)
		for (i=0;i<size-j;i++)
			if (strcmp(n[i],n[i+1])>0)
			{
				swap (n[i],n[i+1]);
				swap (g[i],g[i+1]);//If we swap the names, we have to swap the corresponding grades as well.
			}
				
}
//I decided to write another bubblesort function for sorting the grades.
void bubblesort_grades (int g[],int size,char *n[])
{
	int i,j;
	for (j=1;j<size-1;j++)
		for (i=0;i<size-j;i++)
			if (g[i]>g[i+1])
			{
				swap (g[i],g[i+1]);
				swap (n[i],n[i+1]); //Just like in the previous function, we swap the names along with the grades.
			}
				
}
int main(int argc, char** argv) {
	int grade[12]={93,68,87,98,45,82,88,75,90,62,78,99},n=1,i,k=0;
	//I set n to not equal 0 so my loop will run.
	char *name[12]={"Simmons","Rogers","Trueman","Roberts","Myers","Kinney","Baar","Lennon","Cohen","Wallah","Vernon","Psomas"},srch[20];
	//Here I'm creating the menu to interact with the user. User determines when the program ends.
	while (n != 0)
	{
		cout<<"Please select one of the following options(0 ends program): "<<endl<<"1.Sort by name"<<endl<<"2.Sort by grade"<<endl
		<<"3.Search for student's grade"<<endl<<"4.Find student(s) with certain grade or over"<<endl;
		cin>>n;
		if (n == 0)
		{
			cout<<"Thank you for using this program."<<endl;
			return 0;
		}
		else if (n == 1) //Option one sorts the data in alphabetical order.
		{
			bubblesort_names (name,12,grade);
			for (i=0;i<12;i++)
				cout<<name[i]<<"\t"<<grade[i]<<endl;
		}
		else if (n == 2) //Option two sorts the data in numerical order.
		{	
			bubblesort_grades (grade,12,name);
			for (i=0;i<12;i++)
				cout<<name[i]<<"\t"<<grade[i]<<endl;
		}
		else if (n == 3) //Option three lets the user search for a student's grade.
		{
			cout<<"Enter student's name: ";
			cin>>srch;
			i=0;
			while(strcmp(name[i],srch)!= 0 && i<12)
				i++;
			if (i==12)
				cout<<"Student not found"<<endl;
			else
				cout<<srch<<"'s grade: "<<grade[i]<<endl;
		}
		else if (n == 4) //Option four finds students with a certain grade or over.
		{
			cout<<"Enter the grade minimum:"<<endl;
			cin>>k;
			for (i=0;i<12;i++)
			{
				if (grade[i]>=k)
					cout<<name[i]<<endl;
			}
		}
		else //This is for when the user does not enter a valid option.
			cout<<"Invalid option. Please select again."<<endl;
	}

}
