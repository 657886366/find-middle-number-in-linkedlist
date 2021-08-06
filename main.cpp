//
//  main.cpp
//  Project 1 construct Linked list
//
//  Created by Conghui Deng on 2/4/20.
//  Copyright © 2020 Conghui Deng. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
using namespace std;

struct listNode{
    int data;
    listNode *next;
    
    listNode(){
        
    }
    
};
void printNode(listNode *Node,ofstream &outFile){
    
    if(Node->next==NULL){
        outFile<<"("<<Node->data<<")->NULL"<<endl;
    }
    else
    outFile<<"("<<Node->data<<")"<<endl;
}
listNode *findOneThirdNode(listNode *listHead,ofstream &outFile2){
    listNode *walk1=listHead;
    listNode *walk2=listHead;
    
    while(walk2!=NULL&&walk2->next!=NULL){
        printNode(walk1,outFile2);
        walk1=walk1->next;
        walk2=walk2->next->next->next;
    }
    return walk1;
}

    listNode *defListHead(int val){
        listNode *temp=new listNode();
        temp->data=-9999;
        temp->next=NULL;
        
        return temp;
    }

   listNode *findSpot(listNode *listHead, listNode *newNode){
      listNode *temp=listHead;
       while(temp->next!=NULL && (temp->next->data)<=newNode->data){
           temp=temp->next;
       }
       return temp;
}
     void listInsert(listNode *listHead,listNode *newNode){
         listNode *Spot=findSpot(listHead,newNode);
         newNode->next=Spot->next;
         Spot->next=newNode;
 }

void printList(listNode *listHead,ofstream &outFile){
    outFile<<"listHead->";
    listNode *temp=listHead;
    while(temp->next!=NULL){
        outFile<<"("<<temp->data<<", "<<temp->next->data<<")->";
        temp=temp->next;
    }
    outFile<<"("<<temp->data<<")->"<<"NULL"<<endl;
}
    void constructLL(listNode *listHead, ifstream &inFile, ofstream &outFile2){
        //char StringFromFile[8];
        int val;
        while(!inFile.eof()){
            inFile>>val;
          //  val=(int)StringFromFile;
            listNode *newNode=new listNode();
            newNode->data=val;
            newNode->next=NULL;
            listInsert(listHead,newNode);
            printList(listHead,outFile2);
        }
        //cout<<"test";
    }

int main(int argc, const char *argv[]){
    ifstream inFile (argv[1]);
    ofstream outFile(argv[2]);
    ofstream outFile2(argv[3]);
  
    listNode *listHead=new listNode();

    listHead=defListHead(-9999);
    constructLL(listHead,inFile,outFile2);
    printList(listHead,outFile);
    outFile2<<endl<<"Finding Middle Node: "<<endl;
    listNode *oneThirdNode=findOneThirdNode(listHead,outFile2);
    outFile<<endl<<"OneThirdNode: "<<endl;
    printNode(oneThirdNode,outFile);
    inFile.close();
    outFile.close();
    outFile2.close();
}
