#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

  class Trie
  {
  	  public:
         Trie * children[26];
         bool endOfWord;
         string Meaning;


   Trie()
   {
	for(int i=0;i<26;i++)
	{
	children[i]=NULL;
	}
	
   }
   
   Trie *getNode(void)
  {
       Trie *temp=new Trie;
      temp->endOfWord=false;
      int i;
      for(i=0;i<26;i++)
      {
          temp->children[i]=NULL;
      }
		temp->Meaning= "NULL";

	temp->endOfWord =false;
      return temp;
  }

void insert(Trie *root,string s,string meaning)
{
     Trie *temp=root;
    int i,k;
    for(i=0;i<s.length();i++)
    {
      
	    k=s[i]-'A';
        if(!temp->children[k])
        {
            temp->children[k]=getNode();
        }
        temp=temp->children[k];
      
    }
    temp->endOfWord=true;
	temp->Meaning=meaning;
	

}

bool search(Trie *root,string s)
{
    Trie *temp=root;
    int i,k;
    for(i=0;i<s.length();i++)
    {
       k=s[i]-'A';
     
        if(temp->children[k]==NULL)
        {
            return false;
        }
       temp=temp->children[k];
      }
     if(temp->endOfWord && temp!=NULL)
     {
     	cout<<"searched word is:"<<s<<endl;
	
			if(temp->Meaning!= "NULL")
			{
				cout<<"Meaning:"<<temp->Meaning<< endl;
				return true;
			}
		
     	
     	}
	 return false;

}

void prefixSuggestions(Trie *root,string s)
{
	int i,f=0;
    if(root->endOfWord)
    {
        cout<<"suggested words:"<<s<<endl;

    }
 for(i=0;i<26;i++)
    {
  if(root->children[i])
        {
            f=1;
            break;
        }
    }
    if(!f)
        return;
    for(i=0;i<26;i++)
    {
        if(root->children[i])
        {
            s.push_back(65+i);
            prefixSuggestions(root->children[i],s);
            s.erase(s.size()-1);
        }
      }
   }




void prefixSearch(Trie *root,string s)
{
    Trie *temp=root;
    int i,k,f=0;
   for(i=0;i<s.length();i++)
    {
        k=s[i]-'A';
        if(!temp->children[k])
        {
            return;
        }
        temp=temp->children[k];

    }
    for(i=0;i<26;i++)
    {
        if(temp->children[i])
        {
            f=1;
            break;
        }
    }
    if(temp==NULL)
        return;
    if(!f && temp->endOfWord)
    {
        cout<<s<<endl;
        return;
    }
  prefixSuggestions(temp,s);
  }
      
  Trie* MakeTrie(Trie* root)
	{
	fstream obj,fo;
	obj.open("WORDS.txt", ios::in);
	fo.open("Scrabble.txt",ios::in);
	string word,meaning;
	for (int i = 0; i < 279496; i++)
	{
		getline(obj, word);
		getline(fo, meaning);
		//cout<<"word:"<<word;
		//cout<<"meaning:"<<meaning;
		if (word == "")
		{
			goto x;
		}
		
		insert(root, word, meaning);
	x:;
		
	}
	
	return root;
}
	  	
		  
  ~Trie()
	{
	for (int i = 25; i >= 0; i--)
	{
		delete (children[i]);
	}
}

  };

     anschoice()
     {
     	cout<<"\n1)to enter the word\n2)to get suggestions:\n enter choice in number form:";
	 }

 main()
{
	system("Color 04");
	Trie tree,*root;
	 root= tree.getNode();
	 root = tree.MakeTrie(root);
	char x,y;
	int a,b1,b2,r=5,s1=0,s2=0,d,e,z,w;
	string p1,p2,word1,word2,ch,ch1;
	cout<<"                      :::  WELCOME TO THE SCRABBLE GAME :::     ";
	cout<<endl<<endl<<endl;
	cout<<endl;
	cout<<" Let's start with the rules :: "<<endl;
	cout<<" 1 : First of all both the players will login their respeective names . "<<endl;
	cout<<" 2 : Than each player will be given a random letter by computer . "<<endl;
	cout<<" 3 : Players have to than type the longest possible word from that letter . "<<endl;
	cout<<" 4 : Each letter of the word will provide the player with 1 point . "<<endl;
	cout<<" 5 : After some successful rounds , the one with maximum Score will win . "<<endl;
	cout<<endl<<endl;
	cout<<" NOTE : All the words entered here should be meaningful and if any player \n enters a meaningless word than he will be disqualified !! "<<endl;

	cout<<endl;
	cout<<"                              PRESS 1 TO CONTINUE ..... ";
	cout<<endl;
	cout<<"                              PRESS 0 TO QUIT     ..... ";

	cin>>a;

	if(a==1)
	{
	system("CLS");
		cout<<"                      :::  WELCOME TO THE SCRABBLE GAME :::     ";
		cout<<endl<<endl<<endl;
		cout<<" Let's log in to play the Game Of Scrabbling "<<endl;
		cout<<endl;
		cout<<" Player 1 : "; cin>>p1;
		cout<<endl;
		cout<<" Player 2 : "; cin>>p2;
		cout<<endl<<endl;

		cout<<"                     You Both have got quite nice names !!"<<endl;
		cout<<endl<<" Now Enter the number of Rounds :: ";
		cin>>r;
		w=r;
		cout<<endl<<endl;
		cout<<"                    Let's see who is the better Scabbler "<<endl;
		cout<<"                    Will it be "<<p1<<" or Will it be "<<p2<<endl<<endl;
		cout<<endl<<"                     PRESS 1 TO CONTINUE ..... ";
		cin>>a;

		if(a==1)
		{
			while(r>0)
			{
			system("CLS");
				start :
				cout<<"                      :::  WELCOME TO THE SCRABBLE GAME :::     ";
				cout<<endl<<endl<<endl;
				cout<<" Player 1 : "<<p1<<"           ROUNDS LEFT :  "<<r<<"             Player 2 : "<<p2<<endl;
				cout<<" Score    : "<<s1<<"                                              Score    : "<<s2<<endl;

				cout<<endl<<endl;
				z=rand()%26+65;
				x=toupper(z);
				cout<<"   "<<p1<<" Your letter is : "<<x<<" : ";
                anschoice();
                int g;
                string t;
                bool ans;
                cin>>g;
                if(g==1)
                {
                	cin>>word1;
                
				if(tree.search(root,word1))
				{
					s1=s1+word1.length();
				}
				else
				{
					cout<<p1<<"Disqualified due to wrong word";
					return 1;
				}
				}
				else
				{
					cout<<"enter word starting for suggestions:";
					cin>>t;
				tree.prefixSearch(root,t);
				}
                 

				cout<<endl<<endl;
				z=rand()%26+65;
				x=toupper(z);
				cout<<p2<<" Your letter is : "<<x<<" : ";
			
				anschoice();
                cin>>g;
                if(g==1)
                {
                	cin>>word2;
				if(tree.search(root,word2))
				{
					
				s2=s2+word2.length();
				}
				else
				{
					cout<<p2<<"Disqualified due to wrong word";
					return 1;
				}
				}
				else
				{
					cout<<"enter word starting for suggestions:";
					cin>>t;
				tree.prefixSearch(root,t);
				}
                 
				r=r-1;
				if(r>=1)
				{
		
				}
				else {
					cout<<endl<<endl<<"                      PRESS ENTER TO CONTINUE ..... ";
					getch();
				 }



			}

		}

		if(s1==s2)
			{
		system("CLS");
			cout<<"                      :::  WELCOME TO THE SCRABBLE GAME :::     ";
			cout<<endl<<endl<<endl;
			cout<<"          FINAL RESULTS AFTER "<<w<<" ROUNDS ARE :::: "<<endl;
			cout<<endl<<endl;
			cout<<"     "<<p1<<"    : "<<s1<<endl;
			cout<<"     "<<p2<<"    : "<<s2<<endl;
			cout<<endl<<endl;
			cout<<" OH NO !!! , It's a draw . Let's have one SUPER ROUND "<<endl;
			r=1;
			w=w+1;
			cout<<endl<<endl<<"                     PRESS ENTER TO CONTINUE ....";
			getch();
		system("CLS");
			goto start;
			}
	     system("CLS");
		cout<<"                      :::  WELCOME TO THE SCRABBLE GAME :::     ";
		cout<<endl<<endl<<endl;
		cout<<"          FINAL RESULTS AFTER "<<w<<" ROUNDS ARE :::: "<<endl;
		cout<<endl<<endl;
		cout<<"         "<<p1<<"    : "<<s1<<endl;
		cout<<"         "<<p2<<"    : "<<s2<<endl;
		cout<<endl<<endl;
		if(s1>s2)
		{ ch=p1 ;}

		else if(s2>s1)
		{ ch=p2; }
		cout<<" So finally we have out biggest Scrabbler i.e "<<ch;

		}
		else if(a==0)
			{
				exit(0);
			}
		cout<<endl<<endl;
		cout<<"                    PRESS ENTER TO EXIT.....    ";
	getch();
}

