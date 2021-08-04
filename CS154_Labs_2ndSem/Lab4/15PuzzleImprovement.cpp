#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>


using namespace std;

char* int2charstar (int v) {
 char *s = new char[sizeof(int)];
 sprintf(s,"%d",v);
 return s;
}


int getInvCount(vector<int> arr, int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;

    return inv_count;
}


//static const char* textLabels1[17] = {"0","1","2","3","4","5","6","7","8",
//            "9","10","11","12","13","14","15","xx" };


vector<const char*>  textLabels;




class ButtonData{
public:
int id;
string txt;

Fl_Button* selfAdd; // Stands for self's address
Fl_Button* leftAdd; // Stands for left neighbour's address
Fl_Button* rightAdd;
Fl_Button* upAdd;
Fl_Button* downAdd;
};


map<int, ButtonData*> idToBtnData;

vector<const char*> clickHistory;
vector<const char*> markerMovement;




void button1_cb(Fl_Widget* widget,void *data){





Fl_Button* buttonptr = (Fl_Button*)widget;

ButtonData* btndata = (ButtonData*)data;


   int id = btndata->id;
   clickHistory.push_back(btndata->selfAdd->label());
//cout<<id<<endl;


   /// Check for Left Position
   //Conveniently avoids 'corner squares not having left neighbours' by comparing address pointers with the NULL pointers

   if(btndata->leftAdd != NULL){
       //cout<<"Left btn Label="<<btndata->leftAdd->label()<<"  self  Label="<<btndata->selfAdd->label()<<endl;
if(btndata->leftAdd->label()==textLabels[16]){
btndata->leftAdd->label(btndata->selfAdd->label());
btndata->selfAdd->label(textLabels[16]);
markerMovement.push_back(btndata->selfAdd->label());
}

}

/// Check for right Position
if(btndata->rightAdd != NULL){
//cout<<"right btn Label="<<btndata->rightAdd->label()<<"  self  Label="<<btndata->selfAdd->label()<<endl;

if(btndata->rightAdd->label()==textLabels[16]){
btndata->rightAdd->label(btndata->selfAdd->label());
btndata->selfAdd->label(textLabels[16]);
markerMovement.push_back(btndata->selfAdd->label());
}
}


/// Check for up Position
if(btndata->upAdd != NULL){
//cout<<"right btn Label="<<btndata->rightAdd->label()<<"  self  Label="<<btndata->selfAdd->label()<<endl;

if(btndata->upAdd->label()==textLabels[16]){
btndata->upAdd->label(btndata->selfAdd->label());
btndata->selfAdd->label(textLabels[16]);
markerMovement.push_back(btndata->selfAdd->label());
}
}


/// Check for down Position
if(btndata->downAdd != NULL){
//cout<<"right btn Label="<<btndata->rightAdd->label()<<"  self  Label="<<btndata->selfAdd->label()<<endl;

if(btndata->downAdd->label()==textLabels[16]){
btndata->downAdd->label(btndata->selfAdd->label());
btndata->selfAdd->label(textLabels[16]);
markerMovement.push_back(btndata->selfAdd->label());
}
}




    // Game Over Check
    if(    id == 1
             &&
           btndata->selfAdd->label()==textLabels[16])
{

cout<<"Game Over"<<endl;
cout<<"Printing Click History\n";

for(int i = 0; i < clickHistory.size();++i){
cout<<clickHistory.at(i)<<"=>";
}

cout<<"Game Over\n";
/*
cout<<"Printing Path of Marker Movement\n";
for(int j=0;j<markerMovement.size();++j){
cout<<markerMovement.at(j)<<"=>";
}
*/
cout<<"Game Over\n";


for(int k=0;k<3;++k)
{
cout<<"Game Over\n";
sleep(1);
}



exit(0);
}

}







int main(int argc, char **argv) {

  srand(time(NULL));
  vector<int>  arr;
  for(int i = 0; i < 15; i++){
    arr.push_back(i+1);
  }

  while(true){
    random_shuffle(arr.begin(), arr.end());
    if(getInvCount(arr, 15)%2 == 0) break;}

    vector<string>  textLabels;

    for(int i = 0; i < arr.size(); i++){
      textLabels.push_back("gold");
    }





    for(int i = 0; i < arr.size(); i++){
        int num = arr[i]; // a variable of int data type

        string str; // a variable of str data type

        // using the stringstream class to insert an int and
        // extract a string
        stringstream ss;
        ss << num;
        ss >> str;


      //const char* c = int2charstar(arr[i]);
      textLabels.push_back(str);
    }

    string c = "xx";
    textLabels.push_back(c);






  int xpos[4] = {50,125,200,275};//x-ccordinates of the buttons
  int ypos[4] = {50,125,200,275};//y-ccordinates of the buttons
  int wd = 50;//width of the buttons
  int ht = 50;//height of the buttons
  int count = 1;





  Fl_Window *window = new Fl_Window(400,400,"15PuzzleGame");




  for(int rw = 0;rw < 4;++rw)
    {
      for(int cl = 0;cl < 4;++cl)
         {
           Fl_Button * btn = new  Fl_Button(xpos[cl],  ypos[rw], wd, ht,  textLabels[count]);
             //cout<<btn->label()<<endl;
//idToBtnAddMap[count]=btn;
            ButtonData *bd = new ButtonData;

bd->id=count;
bd->txt= string(textLabels[count]);
bd->selfAdd = btn;
bd->leftAdd = NULL;
bd->rightAdd = NULL;
bd->upAdd = NULL;
bd->downAdd = NULL;

                   idToBtnData[count] =bd;
                   btn->callback(button1_cb,bd);

       count++;
}
    }

   // First row

        int index=1;

idToBtnData[index]->rightAdd = idToBtnData[index+1]->selfAdd;
idToBtnData[index]->downAdd  = idToBtnData[index+4]->selfAdd;



        for(index=2;index<=3;++index){
idToBtnData[index]->leftAdd=  idToBtnData[index-1]->selfAdd;
idToBtnData[index]->rightAdd= idToBtnData[index+1]->selfAdd;
idToBtnData[index]->downAdd=  idToBtnData[index+4]->selfAdd;
}


        index=4;
idToBtnData[index]->leftAdd=idToBtnData[index-1]->selfAdd;
//idToBtnData[4].rightAdd=
idToBtnData[index]->downAdd=idToBtnData[index+4]->selfAdd;


// second row
        index=5;
idToBtnData[index]->rightAdd=idToBtnData[index+1]->selfAdd;
idToBtnData[index]->downAdd = idToBtnData[index+4]->selfAdd;
        idToBtnData[index]->upAdd   =   idToBtnData[index-4]->selfAdd;

    for(index=6;index<=7;++index){

idToBtnData[index]->leftAdd  = idToBtnData[index-1]->selfAdd;
idToBtnData[index]->rightAdd = idToBtnData[index+1]->selfAdd;
idToBtnData[index]->downAdd  = idToBtnData[index+4]->selfAdd;
        idToBtnData[index]->upAdd    = idToBtnData[index-4]->selfAdd;

}



        index=8;

idToBtnData[index]->leftAdd=idToBtnData[index-1]->selfAdd;
//idToBtnData[4].rightAdd=
idToBtnData[index]->downAdd = idToBtnData[index+4]->selfAdd;
        idToBtnData[index]->upAdd   = idToBtnData[index-4]->selfAdd;


// third row


        index=9;
        idToBtnData[index]->rightAdd =  idToBtnData[index+1]->selfAdd;
idToBtnData[index]->downAdd  =  idToBtnData[index+4]->selfAdd;
        idToBtnData[index]->upAdd    =  idToBtnData[index-4]->selfAdd;






                for(index=10;index<=11;++index){

idToBtnData[index]->leftAdd  =  idToBtnData[index-1]->selfAdd;
idToBtnData[index]->rightAdd =  idToBtnData[index+1]->selfAdd;
idToBtnData[index]->downAdd  =  idToBtnData[index+4]->selfAdd;
        idToBtnData[index]->upAdd    =  idToBtnData[index-4]->selfAdd;


}




                 index=12;
idToBtnData[index]->leftAdd=idToBtnData[index-1]->selfAdd;
//idToBtnData[4].rightAdd=
idToBtnData[index]->downAdd = idToBtnData[index+4]->selfAdd;
        idToBtnData[index]->upAdd   = idToBtnData[index-4]->selfAdd;


// fourth row
idToBtnData[13]->rightAdd=idToBtnData[13+1]->selfAdd;
idToBtnData[13]->upAdd=idToBtnData[13-4]->selfAdd;


idToBtnData[14]->leftAdd=idToBtnData[14-1]->selfAdd;
idToBtnData[14]->rightAdd=idToBtnData[14+1]->selfAdd;
idToBtnData[14]->upAdd=idToBtnData[14-4]->selfAdd;

idToBtnData[15]->leftAdd=idToBtnData[15-1]->selfAdd;
idToBtnData[15]->rightAdd=idToBtnData[15+1]->selfAdd;
idToBtnData[15]->upAdd=idToBtnData[15-4]->selfAdd;

idToBtnData[16]->leftAdd=idToBtnData[16-1]->selfAdd;
idToBtnData[16]->upAdd   = idToBtnData[16-4]->selfAdd;




//markerMovement.push_back("xx");



  window->end();
  window->show(argc, argv);
  return Fl::run();
}
