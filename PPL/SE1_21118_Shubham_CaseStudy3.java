import java.util.*;
import java.io.*;
class Account{
    String name;
    private String password;
    private double balance;
    Account(){
        Scanner scan = new Scanner(System.in);
        System.out.print("Name: ");
        while(!scan.hasNext()){}
        name = scan.nextLine();
        System.out.print("Password: ");
        while(!scan.hasNext()){}
        password=scan.nextLine();
        balance=0;
        System.out.println("Created Successfully");
    }
    Boolean verifyuser(){
        Scanner scan = new Scanner(System.in);
        System.out.print("Password to verify: ");
        while(!scan.hasNext()){}
        String pass=scan.nextLine();
        return password.equals(pass);
    }
    Boolean transact(double amt){
        if(verifyuser()){
            balance+=amt;
            System.out.println("Transaction successful!");
            return true;
        }else{
            System.out.println("Wrong password!");
            System.out.println("Transaction unsuccessful!");
            return false;
        }
    }
    double getbalance(){
        return balance;
    }
}
class Bank{
    int customercount=0;
    Account[] accounts=new Account[10];
    void create(){
        accounts[customercount]=new Account();
        customercount++;
    }
    void performT(){
        Scanner scan = new Scanner(System.in);
        System.out.print("amt: ");
        while(!scan.hasNext()){}
        double b=scan.nextDouble();
        System.out.print("acc id: ");
        while(!scan.hasNext()){}
        int id=scan.nextInt();
        accounts[id].transact(b);
    }
    void display(int id){
        System.out.println(id);
        System.out.println(accounts[id].name);
        System.out.println(accounts[id].getbalance());
        System.out.println();
    }
    void displayAll(){
        for(int i=0;i<customercount;i++){
            display(i);
        }
    }
}
class Main {
  public static void main(String[] args) {
    int c;Bank bank=new Bank();
    Scanner scan = new Scanner(System.in);
    while(true){
        System.out.println("What to perform?");
        System.out.println("1. Create new Account");
        System.out.println("2. Perform transaction");
        System.out.println("3. Display my account");
        System.out.println("4. Display all accounts");
        System.out.println("0. Exit");
        System.out.println();
        while(!scan.hasNext()){}
        c=scan.nextInt();
        if(c==0){ scan.close();break;}
        switch(c){
            case 1: bank.create();break;
            case 2: bank.performT();break;
            case 3: System.out.print("account id: ");while(!scan.hasNext()){}c=scan.nextInt();bank.display(c);break;
            case 4: bank.displayAll();break;
            default:;
        }
    }
    System.out.println("Done!");
  }
}
/*
Sample tested:

What to perform?
1. Create new Account
2. Perform transaction
3. Display my account
4. Display all accounts
0. Exit

1
Name: Haykins
Password: haykins
Created Successfully
What to perform?
1. Create new Account
2. Perform transaction
3. Display my account
4. Display all accounts
0. Exit

1
Name: Verma
Password: verma
Created Successfully
What to perform?
1. Create new Account
2. Perform transaction
3. Display my account
4. Display all accounts
0. Exit

1
Name: Lee
Password: lee
Created Successfully
What to perform?
1. Create new Account
2. Perform transaction
3. Display my account
4. Display all accounts
0. Exit

1
Name: Charlie
Password: charlie
Created Successfully
What to perform?
1. Create new Account
2. Perform transaction
3. Display my account
4. Display all accounts
0. Exit

2
amt: 2365
acc id: 0
Password to verify: haykins
Transaction successful!
What to perform?
1. Create new Account
2. Perform transaction
3. Display my account
4. Display all accounts
0. Exit

2
amt: 2154
acc id: 1
Password to verify: verma
Transaction successful!
What to perform?
1. Create new Account
2. Perform transaction
3. Display my account
4. Display all accounts
0. Exit

2
amt: 135
acc id: 2
Password to verify: leee
Wrong password!
Transaction unsuccessful!
What to perform?
1. Create new Account
2. Perform transaction
3. Display my account
4. Display all accounts
0. Exit

2
amt: 135
acc id: 2
Password to verify: lee
Transaction successful!
What to perform?
1. Create new Account
2. Perform transaction
3. Display my account
4. Display all accounts
0. Exit

3
account id: 1
1
Verma
2154.0

What to perform?
1. Create new Account
2. Perform transaction
3. Display my account
4. Display all accounts
0. Exit

4
0
Haykins
2365.0

1
Verma
2154.0

2
Lee
135.0

3
Charlie
0.0

What to perform?
1. Create new Account
2. Perform transaction
3. Display my account
4. Display all accounts
0. Exit

0
Done!
*/