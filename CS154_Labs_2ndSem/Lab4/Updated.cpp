#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>


using namespace std;


static const char* textLabels[17] = {"0","1","2","3","4","5","6","7","8",
            "9","10","11","12","13","14","15","xx" };



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

vector<int> clickHistory;
vector<int> markerMovement;




void button1_cb(Fl_Widget* widget,void *data){

Fl_Button* buttonptr = (Fl_Button*)widget;

ButtonData* btndata = (ButtonData*)data;


   int id = btndata->id;
   clickHistory.push_back(id);
//cout<<id<<endl;


   /// Check for Left Position
   //Conveniently avoids 'corner squares not having left neighbours' by comparing address pointers with the NULL pointers

   if(btndata->leftAdd != NULL){
       //cout<<"Left btn Label="<<btndata->leftAdd->label()<<"  self  Label="<<btndata->selfAdd->label()<<endl;
if(btndata->leftAdd->label()==textLabels[16]){
btndata->leftAdd->label(btndata->selfAdd->label());
btndata->selfAdd->label(textLabels[16]);
markerMovement.push_back(id);
}

}

/// Check for right Position
if(btndata->rightAdd != NULL){
//cout<<"right btn Label="<<btndata->rightAdd->label()<<"  self  Label="<<btndata->selfAdd->label()<<endl;

if(btndata->rightAdd->label()==textLabels[16]){
btndata->rightAdd->label(btndata->selfAdd->label());
btndata->selfAdd->label(textLabels[16]);
markerMovement.push_back(id);
}
}


/// Check for up Position
if(btndata->upAdd != NULL){
//cout<<"right btn Label="<<btndata->rightAdd->label()<<"  self  Label="<<btndata->selfAdd->label()<<endl;

if(btndata->upAdd->label()==textLabels[16]){
btndata->upAdd->label(btndata->selfAdd->label());
btndata->selfAdd->label(textLabels[16]);
markerMovement.push_back(id);
}
}


/// Check for down Position
if(btndata->downAdd != NULL){
//cout<<"right btn Label="<<btndata->rightAdd->label()<<"  self  Label="<<btndata->selfAdd->label()<<endl;

if(btndata->downAdd->label()==textLabels[16]){
btndata->downAdd->label(btndata->selfAdd->label());
btndata->selfAdd->label(textLabels[16]);
markerMovement.push_back(id);
}
}




    // Game Over Check
    if(    id==1
             &&
           btndata->selfAdd->label()==textLabels[16])
{

cout<<"Game Over"<<endl;
cout<<"Printing Click History\n";

for(int i=0;i<clickHistory.size();++i){
cout<<clickHistory.at(i)<<"=>";
}

cout<<"Game Over\n";

cout<<"Printing Path of Marker Movement\n";
for(int j=0;j<markerMovement.size();++j){
cout<<markerMovement.at(j)<<"=>";
}

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

  int xpos[4] = {50,125,200,275};//x-ccordinates of the buttons
  int ypos[4] = {50,125,200,275};//y-ccordinates of the buttons
  int wd = 50;//width of the buttons
  int ht = 50;//height of the buttons
  int count = 1;



  Fl_Window *window = new Fl_Window(400,400,"15PuzzleGame");
//  window->tooltip("A Simple Click Game.Designed and Coded by Arpon Basu");
  //window->title("A Simple Click Game.Desined and Coded by Arpon Basu");
  //Fl_Box *box = new Fl_Box(20,40,300,100,"Hello, World!");



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
/*idToBtnData[2]->leftAdd=idToBtnData[2-1]->selfAdd;
idToBtnData[2]->rightAdd=idToBtnData[2+1]->selfAdd;
idToBtnData[2]->downAdd=idToBtnData[2+4]->selfAdd;


idToBtnData[3]->leftAdd=idToBtnData[3-1]->selfAdd;
idToBtnData[3]->rightAdd=idToBtnData[3+1]->selfAdd;
idToBtnData[3]->downAdd=idToBtnData[3+4]->selfAdd;*/

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


  /*idToBtnData[6]->leftAdd=idToBtnData[6-1]->selfAdd;
idToBtnData[6]->rightAdd=idToBtnData[6+1]->selfAdd;
idToBtnData[6]->downAdd=idToBtnData[6+4]->selfAdd;
        idToBtnData[6]->upAdd=idToBtnData[6-4]->selfAdd;

idToBtnData[7]->leftAdd=idToBtnData[7-1]->selfAdd;
idToBtnData[7]->rightAdd=idToBtnData[7+1]->selfAdd;
idToBtnData[7]->downAdd=idToBtnData[7+4]->selfAdd;
        idToBtnData[7]->upAdd=idToBtnData[7-4]->selfAdd;*/

        index=8;

idToBtnData[index]->leftAdd=idToBtnData[index-1]->selfAdd;
//idToBtnData[4].rightAdd=
idToBtnData[index]->downAdd = idToBtnData[index+4]->selfAdd;
        idToBtnData[index]->upAdd   = idToBtnData[index-4]->selfAdd;


// third row
/*idToBtnData[9]->rightAdd=idToBtnData[9+1]->selfAdd;
idToBtnData[9]->downAdd=idToBtnData[9+4]->selfAdd;
        idToBtnData[9]->upAdd=idToBtnData[9-4]->selfAdd;*/

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
        /*idToBtnData[10]->leftAdd=idToBtnData[10-1]->selfAdd;
idToBtnData[10]->rightAdd=idToBtnData[10+1]->selfAdd;
idToBtnData[10]->downAdd=idToBtnData[10+4]->selfAdd;
        idToBtnData[10]->upAdd=idToBtnData[10-4]->selfAdd;

idToBtnData[11]->leftAdd=idToBtnData[11-1]->selfAdd;
idToBtnData[11]->rightAdd=idToBtnData[11+1]->selfAdd;
idToBtnData[11]->downAdd=idToBtnData[11+4]->selfAdd;
        idToBtnData[11]->upAdd=idToBtnData[11-4]->selfAdd;*/



                 index=12;
idToBtnData[index]->leftAdd=idToBtnData[index-1]->selfAdd;
//idToBtnData[4].rightAdd=
idToBtnData[index]->downAdd = idToBtnData[index+4]->selfAdd;
        idToBtnData[index]->upAdd   = idToBtnData[index-4]->selfAdd;


// fourth row
idToBtnData[13]->rightAdd=idToBtnData[13+1]->selfAdd;
//idToBtnData[13]->downAdd=idToBtnData[9+4]->selfAdd;
idToBtnData[13]->upAdd=idToBtnData[13-4]->selfAdd;


idToBtnData[14]->leftAdd=idToBtnData[14-1]->selfAdd;
idToBtnData[14]->rightAdd=idToBtnData[14+1]->selfAdd;
//idToBtnData[10]->downAdd=idToBtnData[10+4]->selfAdd;
idToBtnData[14]->upAdd=idToBtnData[14-4]->selfAdd;

idToBtnData[15]->leftAdd=idToBtnData[15-1]->selfAdd;
idToBtnData[15]->rightAdd=idToBtnData[15+1]->selfAdd;
//idToBtnData[11]->downAdd=idToBtnData[11+4]->selfAdd;
idToBtnData[15]->upAdd=idToBtnData[15-4]->selfAdd;

idToBtnData[16]->leftAdd=idToBtnData[16-1]->selfAdd;
//idToBtnData[4].rightAdd=
//idToBtnData[12]->downAdd = idToBtnData[12+4]->selfAdd;
idToBtnData[16]->upAdd   = idToBtnData[16-4]->selfAdd;




    markerMovement.push_back(16);


  //cout<< &bd11<<endl;
  //cout<< "***"<<endl;
  //box->box(FL_UP_BOX);
// box->labelfont(FL_BOLD+FL_ITALIC);
  //box->labelsize(36);
  //box->labeltype(FL_SHADOW_LABEL);
  window->end();
  window->show(argc, argv);
  return Fl::run();
}
