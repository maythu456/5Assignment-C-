    //maythu456@gmail.com
    //5 assignment (Exam)
    //OOP create class
	
	
#include<iostream>
 #include<conio.h>
 #include<process.h>
 using namespace std;
 
 int count = 0;
 class staff
 	{
        private: int id;
        		char name[30];
        		char password[30];
        		int amount;
        		int age;
        		char location[50];
  		public: void insert()
  				{
				  	FILE *fp;
		  	 		int i,n=0;
			    
			        fp=fopen("staff.txt","a");
			        if(fp==NULL)
			        {
			            cout<<"\n File Opening Error";
			            exit(0);
			        }
			        cout<<"\n\tHow Many Records You Want to Enter: ";
			       cin>>n;
			        for(i=0;i<n;i++)
			        {
			           cout<<"Enter Staff ID: ";
			           cin>>id;
			
			           cout<<"Enter Staff Name: ";
			           cin>>name;
			           
			                      
			           cout<<"Enter Password: ";
			           cin>>password;
			            
			           cout<<"Enter Staff's Amount: ";
			           cin>>amount;
			
			           cout<<"Enter Staff age: ";
			           cin>>age;
			
			           cout<<"Enter Staff's Location: ";
			           cin>>location;
			            
			           cout<<"\n******************************\n";
			           //fwrite(&s,sizeof(s),1,fp);
			           fprintf(fp, "%d \t %s \t\t %s \t\t %d \t %d \t\t %s\n ", id,name,password,amount,age,location);
			        }
			    	fclose(fp);
			
			 
		  }
		  void find()
		  {
  			
			char searchName[30];
			char name[30];
			int found=0;
			int i=0;
			
			
			cout<<"Enter name to search : ";
			scanf("%s",searchName);
			
			searchName[strlen(searchName)-1] = '\0';
			
			FILE *fp;
			        fp=fopen("staff.txt","r");
			        if(fp==NULL)
			        {
			            printf("can't read file");
			            exit(0);
			        }
			  cout<<"\n*************************\n";
			  cout<<"Staff Data that you want to see!!!!\n";
			 while (fgets(name, 30, fp)) 
			        {
			        	
			             if(strstr(name,searchName))
			            {
			            	cout<< name;
				            found = 1;
			            }
			        }
			        if ( found == 0)
			           cout<<"  cannot be found\n",searchName ;
			         cout<<"\n*************************\n";
			        fclose(fp);
    }

	
  		
  		void show()
  		{
		  	
		char data[50];
		FILE *fp;
        fp=fopen("staff.txt","r");
        if(fp==NULL)
        {
            cout<<"can't read file";
            exit(0);
        }
        
        cout<<"*************************\n";
        cout<<"Show All Staff Data!!!\n";
        
        
         while( fgets ( data, 50, fp ) != NULL )
        {
         
                     cout<< data ;
        }
       cout<<"*************************\n";
         
          fclose(fp);
		  	
		  }
  		void update()
		  {

  			char updateName[30];
			char name[30];
			int found=0;
			int i=0;
			staff s;
			int pos;
			
			
			cout<<"Enter name to update : ";
			scanf("%s",updateName);
			
			updateName[strlen(updateName)-1] = '\0';
			
			FILE *fp;
			        fp=fopen("staff.txt","a+");
			        if(fp==NULL)
			        {
			            printf("can't read file");
			            exit(0);
			        }
			        
   				//pos = fp.tellg();
   				
			  cout<<"*************************\n";
			  cout<<"This is File Update!!!!\n";
			 while (fgets(name, 30, fp)) 
			        {
			        	
			             if(strstr(name,updateName))
			            {
		            	found = 1;
           				cout<<"Enter New Staff ID: ";
	            			cin>>s.id;
	
			           cout<<"Enter New Staff Name: ";
			           cin>>s.name;
			           
			           cout<<"Enter New Password: ";
			           cin>>s.password;
			            
			           cout<<"Enter New Staff's Amount: ";
			           cin>>s.amount;
			
			           cout<<"Enter New Staff age: ";
			           cin>>s.age;
			
			           cout<<"Enter New Staff's Location: ";
			           cin>>s.location;
				           	
						//fwrite(&s,sizeof(s),1,fp);
						
			           fprintf(fp, "%d \t %s \t\t %s \t\t %d \t %d \t\t %s\n", id,name,password,amount,age,location);
			           cout<<"Update Succefully!!";
				           	
		           }
	           
	          }
	            
				       if ( found == 0)
			           cout<<"  cannot be found\n",updateName ;
			         cout<<"*************************\n";
			        fclose(fp);


  		}
 	};
		  	
		  	
int main()
 {
    int option;
    staff s;
   
        while(1)
        {
            cout<<"\n1:Insert Staff Records";
            cout<<"\n2:Find Staff Records";
            cout<<"\n3:Update Records";
            cout<<"\n4: Show Staff Records";
            cout<<"\n5: Exit the Staff Record Program";
            cout<<"\n\tEnter Your Option:  ";
            cin>>option;
            
            switch(option)
            {
                case 1:
                		s.insert();
               			 break;
                case 2:
                		s.find();
                		break;
                case 3:
                		s.update(); break;
          		case 4: 
          				s.show(); break;
          				
				case 5: exit (0); break;
                default:
                		cout<<"Option is not availabel!!";
                		break;
            }
        }
    getch();
    return 0;
  }
  
