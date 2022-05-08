#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int itemnum;
int employeenum;
char animationfile[100]="intro.txt";
char employeefile[100]="employees.txt";
char itemfile[100]="items.txt";
char profitfile[100]="profits.txt";
struct employee{
    char name[50];
    int day;
    int month;
    int year;
    char workingarea[20];
    int joinday;
    int joinmonth;
    int joinyear;
    double NID;
    int salary;
};

struct items{
    char itemname[50];
    int quantity;
    float price;
    char manufacturer[50];
    char area[20];
};


struct items itemarray[1000];
struct employee employeelist[1000];

int digitscount(int a){
    int count = 0;
    if (a==0){
        return 1;
    }
    while (a!=0){
        a = a/10;
        count++;
    }
    //printf("%d",count);
    return count;
}

void billing(){
    displayitems();

    int totalitems;
    printf("How many items would you like to check out (Enter -1 to cancel): ");
    scanf("%d",&totalitems);
    if (totalitems==-1){
        enterdelay();
        return;
    }

    int basket[totalitems];
    int basketquantity[totalitems];
    float totals[totalitems+1];

    int j;
    for (int i = 0;i<totalitems;i++){
        printf("Enter serial of item to enter in basket: ");
        int n;
        scanf("%d",&n);
        n--;
        basket[i]=n;
        //printf("%d\n",basket[i]); //
        printf("Enter quantity: ");
        int q;
        scanf("%d",&q);
        //printf("%d\n",q); //
        while (q>itemarray[n].quantity){
            printf("Quantity cannot be greater than what is in stock.\n");
            printf("Enter quantity: ");
            scanf("%d",&q);
        }
        basketquantity[i]=q;
        itemarray[n].quantity=itemarray[n].quantity-q;

        totals[i]=basketquantity[i]*itemarray[n].price;
    }

    for (int i = 0;i<totalitems;i++){
        totals[totalitems+1]+=totals[i];
    }

    printf(" ______________________________________________________________\n");
    printf("|        Item        |      Quantity      |       Price        |\n");
    printf(" --------------------------------------------------------------\n");

    for (int i = 0;i<totalitems;i++){
        printf("| %s",itemarray[basket[i]]);
        int l = basket[i];
        for (int k = 0;k<19-strlen(itemarray[l].itemname);k++){
            printf(" ");
        }
        printf("|");

        for (int k = 0;k<19-digitscount(basketquantity[i]);k++){
            printf(" ");
        }
        printf("%d |",basketquantity[i]);

        for (int k = 0;k<13-digitscount(totals[i]);k++){
            printf(" ");
        }
        printf("%.2f tk |\n",totals[i]);

    }

    printf(" --------------------------------------------------------------\n");
    printf("|                                           Total |");
    for (int k = 0;k<7-digitscount(totals[totalitems+1]);k++){
        printf(" ");
    }
    printf("%.2ftk|\n",totals[totalitems+1]);
    printf(" --------------------------------------------------------------\n");

    printf("                Thank you for shopping with us!\n");

    writeitemfile();
    enterdelay();
}

void arealist(int a){
    printf("\n");
    int flag = 0;
    if (a==1){
        printf("Items are found in these areas: \n\n");
        for (int i = 0;i<itemnum;i++){
            for (int j=0;j<i;j++){
                if (strcmp(itemarray[j].area,itemarray[i].area)==0){
                    flag++;
                }
            }
            if (flag==0){
                printf("-%s\n",itemarray[i].area);
            }
            flag = 0;
        }
        printf("\n");
        printf("Type option and press enter.\n\n");
        return;
    }
    printf("Employees are working in these areas: \n\n");
    for (int i = 0;i<employeenum;i++){
        for (int j=0;j<i;j++){
            if (strcmp(employeelist[i].workingarea,employeelist[j].workingarea)==0){
                flag++;
            }
        }
        if (flag==0){
            printf("-%s\n",employeelist[i].workingarea);
        }
        flag=0;
        flag=0;
    }
    printf("\n");
    printf("Type option and press enter.\n\n");
}

void numspace(int a,float b,int c){
    int quantityspace = 3;
    int pricespace = 6;
    int digitlen;
    switch(c){
    case 1:
        printf(" ");
        digitlen = digitscount(a);
        for (int i = 1;i<=quantityspace-digitlen;i++){
            printf(" ");
        }
        printf("%d      |",a);
        break;
    case 2:
        printf(" ");
        digitlen = digitscount(b);
        for (int i = 1;i<pricespace-digitlen;i++){
            printf(" ");
        }
        printf("%.2lf tk |",b);
        break;
    case 3:
        if (a<10) printf(" ");
        break;
    }
}

void spaces(char a[],int b){
    int employeenamespace = 20;
    int itemspace = 21;
    int areaspace=15;
    int manufacturerspace = 26;


    switch (b){
    case 1:
        for(int i = 1;i<=employeenamespace-strlen(a);i++){
            printf(" ");
        }
        printf("|");
        break;
    case 2:
        for(int i = 1;i<=areaspace-strlen(a);i++){
            printf(" ");
        }
        printf("|");
        break;
    case 3:
        for(int i = 1;i<=manufacturerspace-strlen(a);i++){
            printf(" ");
        }
        printf("|");
        break;
    }
}

void datespace(int day,int month,int year){
    if (day<10 && month>9){
        printf(" ");
        printf("0");
        printf("%d/%d/%d |",day,month,year);
        return;
    }
    if (day<10 && month<10){
        printf(" ");
        printf("0");
        printf("%d/",day);
        printf("0");
        printf("%d/%d |",month,year);
        return;
    }
    if (day>10 && month<10){
        printf(" ");
        printf("%d/",day);
        printf("0");
        printf("%d/%d |",month,year);
        return;
    }

    printf(" %d/%d/%d |",day,month,year);
}

void enterdelay(){
    char s;
    fflush(stdin);
    while (s!='\n'){
        printf("\n\nPress enter to return to previous menu.");
        scanf("%c",&s);
    }
    return;
}

void lowercase(char a[]){
   for (int i = 0;i<strlen(a);i++){
      if (a[i]>=65 && a[i]<=90){
         a[i]=a[i]+32;
      }
   }
}

void printart(){
    FILE *fp;
    fp = fopen(animationfile,"r");
    if (fp == NULL){
        printf("Intro file not found!");
        return;
    }
    char str[1000];
    while (!feof(fp)){
        fgets(str,1000,fp);
        removeenter(str);
        if (strcmp(str,"/")==0){
            for (int i = 0;i<99990000;i++);
            system("cls");
            fgets(str,1000,fp);
            removeenter(str);
        }
        puts(str);
    }

    fclose(fp);
}

void changeemployeeinfo(){
    char employee[50];
    int flag = 0;
    printf("Enter the proper full name (use display all employees for reference) of the employee you want to change information for (case sensitive): ");
    gets(employee);

    int i = 0;
    for (i = 0;i<employeenum;i++){
        if (strcmp(employee,employeelist[i].name)==0){
            flag++;
            break;
        }
    }
    if (flag==0){
        printf("Employee is not available.");
        return;
    }
    printf("\n _________________________________________________________________________________________");
    printf("\n|     Employee Name    |     DOB    |      Area      |  Join Date |    NID     |  Salary  |\n");
    printf(" -----------------------------------------------------------------------------------------\n");
    printf("| %s ",employeelist[i].name);
    spaces(employeelist[i].name,1);
    datespace(employeelist[i].day,employeelist[i].month,employeelist[i].year);
    printf(" %s",employeelist[i].workingarea);
    spaces(employeelist[i].workingarea,2);
    datespace(employeelist[i].joinday,employeelist[i].joinmonth,employeelist[i].joinyear);
    printf(" %.lf | %d tk |\n",employeelist[i].NID,employeelist[i].salary);
    printf(" -----------------------------------------------------------------------------------------\n");

    printf("Enter 1 to change employee name.\n");
    printf("Enter 2 to change employee DOB.\n");
    printf("Enter 3 to change employee workingarea.\n");
    printf("Enter 4 to change employee join date.\n");
    printf("Enter 5 to change employee NID.\n");
    printf("Enter 6 to change employee salary.\n");
    printf("Enter 7 to cancel.\n");

    int n;
    scanf("%d",&n);
    fflush(stdin);


    switch(n){
    case 1: printf("Enter updated employee name: ");
            gets(employeelist[i].name);
            break;
    case 2: printf("Enter updated employee DOB in this format (dd/mm/yyyy): ");
            scanf("%d/%d/%d",&employeelist[i].day,&employeelist[i].month,&employeelist[i].year);
            break;
    case 3: printf("Enter updated employee working area: ");
            gets(employeelist[i].workingarea);
            break;
    case 4: printf("Enter updated employee join date in this format (dd/mm/yyyy): ");
            scanf("%d/%d/%d",&employeelist[i].joinday,&employeelist[i].joinmonth,&employeelist[i].joinyear);
            break;
    case 5: printf("Enter updated employee NID: ");
            scanf("%lf",&employeelist[i].NID);
            break;
    case 6: printf("Enter updated employee salary: ");
            scanf("%d",&employeelist[i].salary);
            break;
    case 7: return;
    default:printf("Please enter a valid input.");
            return;

    }

    writeemployeefile();

    printf("Employee information change was successful.\n");

    enterdelay();


}

void changeiteminfo(){
    char item[50];
    int flag = 0;
    printf("Enter the proper name of item (use display items for reference) you want to change information for (case sensitive): ");
    gets(item);

    int i = 0;
    for (i = 0;i<itemnum;i++){
        if (strcmp(item,itemarray[i].itemname)==0){
            flag++;
            break;
        }
    }
    if (flag==0){
        printf("Item is not available.");
        enterdelay();
        return;
    }

    printf("\n __________________________________________________________________________\n");
    printf("|      Item Name      | Quantity |    Price    |       Manufacturer        |\n");
    printf(" --------------------------------------------------------------------------\n");

    printf("| %s",itemarray[i].itemname);
    spaces(itemarray[i].itemname,1);
    numspace(itemarray[i].quantity,0,1);
    numspace(0,itemarray[i].price,2);
    printf(" %s",itemarray[i].manufacturer);
    spaces(itemarray[i].manufacturer,3);
    printf("\n");
    printf(" --------------------------------------------------------------------------\n");

    printf("Enter 1 to change item name.\n");
    printf("Enter 2 to change item quantity.\n");
    printf("Enter 3 to change item price.\n");
    printf("Enter 4 to change item manufacturer.\n");
    printf("Enter 5 to change item area.\n");
    printf("Enter 6 to cancel.\n");

    int n;
    scanf("%d",&n);
    fflush(stdin);



    switch(n){
    case 1: printf("Enter new item name: ");
            gets(itemarray[i].itemname);
            break;
    case 2: printf("Enter new item quantity: ");
            scanf("%d",&itemarray[i].quantity);
            break;
    case 3: printf("Enter new item price: ");
            scanf("%f",&itemarray[i].price);
            break;
    case 4: printf("Enter new item manufacturer: ");
            gets(itemarray[i].manufacturer);
            break;
    case 5: printf("Enter new item area: ");
            gets(itemarray[i].area);
            break;
    case 6: return;
    default:printf("Please enter a valid input.");
            return;

    }

    writeitemfile();

    printf("Item information change was successful.\n");

    enterdelay();

}

void employeeareasearch(){
    arealist(0);
    char area[50];
    int flag =0;
    int printflag = 0;
    printf("Enter the area you want to search: ");
    gets(area);

    for (int i =0;i<employeenum;i++){
         if (strcmpi(area,employeelist[i].workingarea)==0){
            if (printflag==0) {
                printf("\n ________________________________________________________________________");
                printf("\n|     Employee Name    |     DOB    |  Join Date |    NID     |  Salary  |\n");
                printf(" ------------------------------------------------------------------------\n");
            }
            printflag++;
            printf("| %s ",employeelist[i].name);
            spaces(employeelist[i].name,1);
            datespace(employeelist[i].day,employeelist[i].month,employeelist[i].year);
            datespace(employeelist[i].joinday,employeelist[i].joinmonth,employeelist[i].joinyear);
            printf(" %.lf | %d tk |\n",employeelist[i].NID,employeelist[i].salary);
            flag++;
         }
    }

    if (flag==0){
        printf("No employee in this area.");
    }
    else {
        printf(" ------------------------------------------------------------------------\n");
    }

    printf("\nFound %d results.\n",flag);
    enterdelay();
}

void itemareasearch(){
    char area[50];
    int flag = 0;
    arealist(1);
    printf("Enter the area you want to search: ");
    gets(area);
    char temp[50];
    lowercase(area);

    for (int i =0;i<itemnum;i++){
        strcpy(temp,itemarray[i].area);
        lowercase(temp);
         if (strncmp(area,temp,strlen(area))==0){
            if (flag == 0){
                    printf("\n __________________________________________________________________________\n");
                    printf("|      Item Name      | Quantity |    Price    |       Manufacturer        |\n");
                    printf(" --------------------------------------------------------------------------\n");
            }
            printf("| %s",itemarray[i].itemname);
            spaces(itemarray[i].itemname,1);
            numspace(itemarray[i].quantity,0,1);
            numspace(0,itemarray[i].price,2);
            printf(" %s",itemarray[i].manufacturer);
            spaces(itemarray[i].manufacturer,3);
            printf("\n");
            flag++;
         }
    }

    if (flag==0){
        printf("No item in this area.");
    }
    else{
        printf(" --------------------------------------------------------------------------\n");
    }
    enterdelay();
}

void lowquantity(){
    int flag = 0;
    printf("\n\n");
    if (itemnum==0){
        printf("No items available.\n");
        return;
    }

    for(int i = 0;i<itemnum;i++){
            if (itemarray[i].quantity<=10){
                if (flag==0) {
                    printf("\n ___________________________________________________________________________________________\n");
                    printf("|      Item Name      | Quantity |    Price    |       Manufacturer        |      Area      |\n");
                    printf(" -------------------------------------------------------------------------------------------\n");
                }
                flag++;
                printf("| %s",itemarray[i].itemname);
                spaces(itemarray[i].itemname,1);
                numspace(itemarray[i].quantity,0,1);
                numspace(0,itemarray[i].price,2);
                printf(" %s",itemarray[i].manufacturer);
                spaces(itemarray[i].manufacturer,3);
                printf(" %s",itemarray[i].area);
                spaces(itemarray[i].area,2);
                printf("\n");
            }
    }

    if (flag == 0){
        printf("No items low in quantity.\n\n");
    }
    else{
        printf(" -------------------------------------------------------------------------------------------\n");
        printf("\nFound %d results.",flag);
    }
    enterdelay();
}

void itemsearch(){
    char item[50];
    int flag=0;
    printf("\nEnter the name of the item you want to search: ");
    gets(item);
    char temp[50];
    lowercase(item);

    for (int i = 0;i<itemnum;i++){//
        strcpy(temp,itemarray[i].itemname);
        lowercase(temp);
        if (strncmp(item,temp,strlen(item))==0){
            if (flag==0) {
                   printf("\n ___________________________________________________________________________________________\n");
                    printf("|      Item Name      | Quantity |    Price    |       Manufacturer        |      Area      |\n");
                    printf(" -------------------------------------------------------------------------------------------\n");
            }
            printf("| %s",itemarray[i].itemname);
            spaces(itemarray[i].itemname,1);
            numspace(itemarray[i].quantity,0,1);
            numspace(0,itemarray[i].price,2);
            printf(" %s",itemarray[i].manufacturer);
            spaces(itemarray[i].manufacturer,3);
            printf(" %s",itemarray[i].area);
            spaces(itemarray[i].area,2);
            printf("\n");
            flag++;
            //return;
        }
    }

    if (flag==0) printf("Item is not available.");
    else {
        printf(" -------------------------------------------------------------------------------------------\n");
        printf("\nFound %d results.",flag);
    }
    enterdelay();
}
void employeesearch(){
    if (employeenum==0){
        printf("\nThere are no employees.\n");
        return;
    }
    char employee[50];
    int flag = 0;
    printf("Enter the name of the employee you want to search: ");
    gets(employee);
    char temp[50];
    lowercase(employee);

    for (int i = 0;i<employeenum;i++){
        strcpy(temp,employeelist[i].name);
        lowercase(temp);
        if (strncmp(employee,temp,strlen(employee))==0){
            if (flag==0){
                printf("\n _________________________________________________________________________________________");
                printf("\n|     Employee Name    |     DOB    |      Area      |  Join Date |    NID     |  Salary  |\n");
                printf(" -----------------------------------------------------------------------------------------\n");
            }
            printf("| %s ",employeelist[i].name);
            spaces(employeelist[i].name,1);
            datespace(employeelist[i].day,employeelist[i].month,employeelist[i].year);
            printf(" %s",employeelist[i].workingarea);
            spaces(employeelist[i].workingarea,2);
            datespace(employeelist[i].joinday,employeelist[i].joinmonth,employeelist[i].joinyear);
            printf(" %.lf | %d tk |\n",employeelist[i].NID,employeelist[i].salary);
            flag++;
        }
    }

    if (flag==0) printf("Employee is not available.");
    else {
        printf(" -----------------------------------------------------------------------------------------\n");
        printf("\nFound %d results.",flag);
    }
    enterdelay();
}
void deleteemployee(){
    displayemployees();
    char employee[50];
    int flag = 0;
    printf("Enter the name of employee you want to delete: ");
    gets(employee);

    for (int i = 0;i<employeenum;i++){
        if (strcmpi(employee,employeelist[i].name)==0){
            for (int j = i;j<employeenum-1;j++){
                employeelist[j] = employeelist[j+1];
            }
            flag++;
            break;
        }
    }

    if (flag != 1){
        printf("Employee was not found.\n");
    }
    else{
        employeenum--;
        writeemployeefile();
        printf("Employee deleted!\n");
    }
    enterdelay();
}

void deleteitem(){
    displayitems();
    char item[50];
    int flag = 0;
    printf("Enter the proper name of item you want to delete: ");
    gets(item);

    for(int i = 0;i<itemnum;i++){
        if (strcmpi(item,itemarray[i].itemname)==0){
            for (int j = i;j<itemnum-1;j++){
                itemarray[j]=itemarray[j+1];
            }
            flag++;
            break;
        }
    }

    if (flag != 1){
        printf("Item was not found.");
    }
    else{
        itemnum--;
        writeitemfile();
        printf("Item has been deleted!");
    }
    enterdelay();
}

void removeenter(char a[]){
    int i = 0;
    while (a[i]!='\0') i++;
    a[i-1]='\0';
}
void displayitems(){

    if (itemnum==0){
        printf("No items available.\n");
        return;
    }

    printf("\n _______________________________________________________________________________________________\n");
    printf("|    |      Item Name      | Quantity |    Price    |       Manufacturer        |      Area      |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");

    for(int i = 0;i<itemnum;i++){

        printf("| %d.",i+1);
        numspace(i+1,0,3);
        printf("| %s",itemarray[i].itemname);
        spaces(itemarray[i].itemname,1);
        numspace(itemarray[i].quantity,0,1);
        numspace(0,itemarray[i].price,2);
        printf(" %s",itemarray[i].manufacturer);
        spaces(itemarray[i].manufacturer,3);
        printf(" %s",itemarray[i].area);
        spaces(itemarray[i].area,2);
        printf("\n");
    }
    printf(" ------------------------------------------------------------------------------------------------\n");
    enterdelay();
}
void displayemployees(){

    if (employeenum==0){
        printf("No employees available.\n");
        return;
    }

    printf("\n _________________________________________________________________________________________");
    printf("\n|     Employee Name    |     DOB    |      Area      |  Join Date |    NID     |  Salary  |\n");
    printf(" -----------------------------------------------------------------------------------------\n");

    for(int i = 0;i<employeenum;i++){
            printf("| %s ",employeelist[i].name);
            spaces(employeelist[i].name,1);
            datespace(employeelist[i].day,employeelist[i].month,employeelist[i].year);
            printf(" %s",employeelist[i].workingarea);
            spaces(employeelist[i].workingarea,2);
            datespace(employeelist[i].joinday,employeelist[i].joinmonth,employeelist[i].joinyear);
            printf(" %.lf | %d tk |\n",employeelist[i].NID,employeelist[i].salary);
    }
    printf(" -----------------------------------------------------------------------------------------\n");
    enterdelay();
}
void inititems(){
    FILE *fp;
    fp = fopen(itemfile,"r");

    if (fp==NULL){
        printf("items.txt file has not been found!\n");
        return;
    }

    fscanf(fp,"%d\n\n",&itemnum);

    for (int i = 0;i<itemnum;i++){
        fgets(itemarray[i].itemname,50,fp);
        removeenter(itemarray[i].itemname);
        fscanf(fp,"%d\n%f\n",&itemarray[i].quantity,&itemarray[i].price);
        fgets(itemarray[i].manufacturer,50,fp);
        removeenter(itemarray[i].manufacturer);
        fgets(itemarray[i].area,20,fp);
        removeenter(itemarray[i].area);
        fscanf(fp,"\n");

    }
    fclose(fp);
}

void initemployees(){
    FILE *fp;
    fp = fopen(employeefile,"r");

    if (fp==NULL){
        printf("employees.txt file has not been found!\n");
        return;
    }

    fscanf(fp,"%d\n\n",&employeenum);

    for (int i = 0;i<employeenum;i++){
        fgets(employeelist[i].name,50,fp);
        removeenter(employeelist[i].name);
        fscanf(fp,"%d/%d/%d\n",&employeelist[i].day,&employeelist[i].month,&employeelist[i].year);
        fgets(employeelist[i].workingarea,20,fp);
        removeenter(employeelist[i].workingarea);
        fscanf(fp,"%d/%d/%d\n",&employeelist[i].joinday,&employeelist[i].joinmonth,&employeelist[i].joinyear);
        fscanf(fp,"%lf\n",&employeelist[i].NID);
        fscanf(fp,"%d\n\n",&employeelist[i].salary);
    }

    fclose(fp);
}

void writeitemfile(){
    FILE *fp;
    fp = fopen(itemfile,"w");
    if (fp==NULL){
        printf("items.txt has not been found.");
        return;
    }

    fprintf(fp,"%d\n\n",itemnum);

    for (int i = 0;i<itemnum;i++){
        fprintf(fp,"%s\n%d\n%f\n%s\n%s\n\n",itemarray[i].itemname,itemarray[i].quantity,itemarray[i].price,itemarray[i].manufacturer,itemarray[i].area);
    }
    fclose(fp);
}

void writeemployeefile(){
    FILE *fp;
    fp = fopen(employeefile,"w");

    fprintf(fp,"%d\n\n",employeenum);
    for (int i = 0;i<employeenum;i++){
        fprintf(fp,"%s\n",employeelist[i].name);
        fprintf(fp,"%d/%d/%d\n",employeelist[i].day,employeelist[i].month,employeelist[i].year);
        fprintf(fp,"%s\n",employeelist[i].workingarea);
        fprintf(fp,"%d/%d/%d\n",employeelist[i].joinday,employeelist[i].joinmonth,employeelist[i].joinyear);
        fprintf(fp,"%.lf\n",employeelist[i].NID);
        fprintf(fp,"%d\n\n",employeelist[i].salary);
    }

    fclose(fp);
}

void additem(){
    printf("Enter item name: ");
    gets(itemarray[itemnum].itemname);
    printf("Enter item quantity: ");
    scanf("%d",&itemarray[itemnum].quantity);
    printf("Enter item price (tk):");
    scanf("%f",&itemarray[itemnum].price);
    fflush(stdin);
    printf("Enter item manufacturer: ");
    gets(itemarray[itemnum].manufacturer);
    printf("Enter area of item: ");
    gets(itemarray[itemnum].area);
    itemnum++;

    writeitemfile();
    printf("Item has been added!\n");
    enterdelay();
}

void addemployee(){
    printf("Enter employee name: ");
    gets(employeelist[employeenum].name);
    printf("Enter employee DOB (dd/mm/yyyy): ");
    scanf("%d/%d/%d",&employeelist[employeenum].day,&employeelist[employeenum].month,&employeelist[employeenum].year);
    fflush(stdin);
    printf("Enter employee working area: ");
    gets(employeelist[employeenum].workingarea);
    printf("Enter employee Joining date (dd/mm/yyyy): ");
    scanf("%d/%d/%d",&employeelist[employeenum].joinday,&employeelist[employeenum].joinmonth,&employeelist[employeenum].joinyear);
    printf("Enter employee NID: ");
    scanf("%lf",&employeelist[employeenum].NID);
    printf("Enter employee salary: ");
    scanf("%d",&employeelist[employeenum].salary);
    employeenum++;

    writeemployeefile();
    printf("\nNew employee has been added!\n");
    enterdelay();
}

void colourart(){
    printf("\033[0;36m");
    printf("\n                                    :::::::::::::::::::::::::::::::::::::");
    printf("\n                                    ::                                 ::");
    printf("\n                                    ::    *************************    ::");
    printf("\n                                    ::    *@@@@@@@@@@@@@@@@@@@@@@@*    ::");
    printf("\n                                    ::    *@                     @*    ::");
    printf("\n                                    ::    *@      WELCOME TO     @*    ::");
    printf("\n                                    ::    *@                     @*    ::");
    printf("\n                                    ::    *@  AGORA SUPER SHOPE  @*    ::");
    printf("\n                                    ::    *@                     @*    ::");
    printf("\n                                    ::    *@@@@@@@@@@@@@@@@@@@@@@@*    ::");
    printf("\n                                    ::    *************************    ::");
    printf("\n                                    ::                                 ::");
    printf("\n                                    :::::::::::::::::::::::::::::::::::::\n\n");
    printf("\033[0m");
}

void profits(){
    FILE *fp;
    fp = fopen(profitfile,"r");

    if (fp==NULL){
        printf("Profit file not found!\n");
        enterdelay();
        return;
    }

    printf("Profits for last week are: \n\n");

    char str[50];

    while (!feof(fp)){
        fgets(str,50,fp);
        removeenter(str);
        puts(str);
    }

    enterdelay();
    fclose(fp);
    return;

}

int main(){
    int usrnum;
    printart();
    while (usrnum!=16){
        colourart();
        inititems();
        initemployees();
        printf("\033[0;33m");
        printf("1: Display all items.\n");
        printf("2: Display all employees.\n");
        printf("3: Add an item.\n");
        printf("4: Add an employee.\n");
        printf("5: Delete an item.\n");
        printf("6: Delete an employee.\n");
        printf("7: Search an item.\n");
        printf("8: Search items that are less than 10 in quantity.\n");
        printf("9: Search a particular employee.\n");
        printf("10: Display all items in particular area.\n");
        printf("11: Display all employees working in a particular area.\n");
        printf("12: Change item information.\n");
        printf("13: Change employee information.\n");
        printf("14: Print a bill.\n");
        printf("15: Show last week profits.\n");
        printf("16: Exit.\n\n");
        printf("Choose your option and press enter: ");
        scanf("%d",&usrnum);
        fflush(stdin);

        if (usrnum<16 && usrnum>0){
            switch(usrnum){
            case 1: displayitems();
                    printf("\n\n");
                    break;
            case 2: displayemployees();
                    printf("\n\n");
                    break;
            case 3: additem();
                    printf("\n\n");
                    break;
            case 4: addemployee();
                    printf("\n\n");
                    break;
            case 5: deleteitem();
                    printf("\n\n");
                    break;
            case 6: deleteemployee();
                    printf("\n\n");
                    break;
            case 7: itemsearch();
                    printf("\n\n");
                    break;
            case 8: lowquantity();
                    printf("\n\n");
                    break;
            case 9: employeesearch();
                    printf("\n\n");
                    break;
            case 10:itemareasearch();
                    printf("\n\n");
                    break;
            case 11:employeeareasearch();
                    printf("\n\n");
                    break;
            case 12:changeiteminfo();
                    printf("\n\n");
                    break;
            case 13:changeemployeeinfo();
                    printf("\n\n");
                    break;
            case 14:billing();
                    printf("\n\n");
                    break;
            case 15:profits();
                    printf("\n\n");
                    break;
            }
        }
        else if (usrnum!=16){
            printf("\nEnter a valid input.\n\n");
        }
        }
    printf("\n---------------------------Thank you---------------------------\n");
    return 0;
}
