#include "snakeonmeteor.h"

List ular;
int turn;
boolean can;
boolean gothitbymeteor;
char * command;
char * before;
infotypeLL meteor;
infotypeLL food;


void move()
{
    infotypeLL kepala = Info(First(ular));   
    infotypeLL temp;
    if((IsStringEqual(command,"W")))
    {
        temp.x = kepala.x;
        temp.y = (kepala.y -1 + 5)%5;
    }

    if((IsStringEqual(command,"S")))
    {
        temp.x = kepala.x;
        temp.y = (kepala.y +1 + 5)%5;
    }

    if(((IsStringEqual(command,"A"))))
    {   
        temp.x = (kepala.x + 5 - 1)%5;
        temp.y = kepala.y;
    }

    if((IsStringEqual(command,"D")))
    {   
        temp.x = (kepala.x + 5 + 1)%5;
        temp.y = kepala.y;
    }

    // masih belum tahu gimana kelanjutannya ini. 
    InsVFirst(&ular, temp);
    infotypeLL sampah;
    DelVLast(&ular,&sampah); //Disini error gatau kenapa
   // printf("HERE");
    
    if(temp.x = food.x && temp.y == food.y)
    {
        infotypeLL ekor = Info(Last(ular));
        ekor.x = (ekor.x -1 + 5)%5;
        if(SearchLL(ular, ekor) == NilLL)
        {
            InsVLast(&ular,ekor);
        }else 
        {
            ekor.x = (ekor.x + 1 + 5)%5;
            ekor.y = (ekor.y -1 +5 )%5;
            if(SearchLL(ular,ekor) == NilLL)
            {
                InsVLast(&ular,ekor);
            }else
            {
                ekor.y = (ekor.y + 2 +5)%5;

                if(SearchLL(ular,ekor ) == NilLL)
                {
                    InsVLast(&ular,ekor);
                }else
                {
                    ekor.y = (ekor.y-1+5)%5;
                    ekor.x= (ekor.x + 1 +5)%5;

                    if(SearchLL(ular,ekor)== NilLL)
                    {
                        InsVLast(&ular,ekor);
                    }else can =false;
                }
            }
        }
    }
    
    
}

void initialize()
{
    turn = 1;
    can = true;
    meteor.x = -1;
    meteor.y = -1;
    CreateEmptyLL(&ular);
    command = (char *) malloc (100 * (sizeof(char)));
    before = (char *) malloc (100*sizeof(char));
    before = "D";
    gothitbymeteor = false;

    // generate koordinat kepala 

    InsVFirst(&ular,createrandominfotype());

    // generate badan pertama
    infotypeLL temp;
    temp = Info(First(ular));
    temp.x= (temp.x - 1 + 5) % 5;
    InsVLast(&ular,temp);

    // generate badan kedua
    temp = Info(Last(ular));
    temp.x = (temp.x - 1 + 5) % 5;
    InsVLast(&ular,temp);    

    makefood();
}

void makemeteor()
{
    meteor = createrandominfotype();

}

void makefood()
{
    food = createrandominfotype();
    while(SearchLL(ular,food) != Nil) food = createrandominfotype();
}

char * bacacommand()
{
    printf("Silahkan masukkan command anda: ");
    STARTWORD();
    char * kata = KataToString(currentKata);
   // if(kata[0] > 90) kata -=32;
    return kata;
}

boolean iscommandvalid(char* cmd )
{
    //if(cmd[0] > 90) cmd[0] -= 32;
    boolean checkinput = (IsStringEqual(cmd,"W") || IsStringEqual(cmd,"A")  || IsStringEqual(cmd,"S")  ||IsStringEqual(cmd,"D") );
    boolean cmdbefore = ((IsStringEqual(cmd,"W") && !IsStringEqual(before,"S")) || (IsStringEqual(cmd,"S") && !IsStringEqual(before,"W")) || (IsStringEqual(cmd,"A") && !IsStringEqual(before,"D")) || (IsStringEqual(cmd,"D") && !IsStringEqual(before,"A")));
    int cmdmeteor = 0;
    int cmdmove = 0;
    infotypeLL kepala = Info(First(ular));
    
    if(cmd == "W")
    {
        cmdmeteor = ((kepala.y -1 +5)% 5) == meteor.y;
        kepala.y = (kepala.y -1 + 5)%5;

    }else if(cmd == "S")
    {
        cmdmeteor = ((kepala.y+1 + 5)%5)  == meteor.y;
        kepala.x = (kepala.x -1 + 5)%5;
    }else if(cmd == "A")
    {
        cmdmeteor = ((kepala.x-1 + 5)%5) == meteor.x;
        kepala.y = (kepala.y + 1 + 5)%5;
    }else if(cmd== "D")
    {
        cmdmeteor = ((kepala.x+1+5)%5) == meteor.x;
        kepala.x = (kepala.x + 1 + 5)%5;
    }

    cmdmove = (SearchLL(ular, kepala) == NilLL);
    if(cmdmeteor == 1) printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut. %d \n", cmdmeteor);

    //printf("%d %d %d %s\n",checkinput,cmdbefore,cmdmeteor,cmd);

    return checkinput && cmdbefore && !cmdmeteor;
}

void printsnake() //ngeprint sklian ngecek kepala dll
{
    printf("Berikut merupakan peta permainan \n\n");
    int j,i;
    for(j = 0;j < 5;j++)
    {
        for(i = 0;i < 5;i++)
        {
            infotypeLL temp;
            temp.x = i;
            temp.y = j;

            printf(" ");
            if(temp.x == meteor.x && temp.y == meteor.y)
            {
                printf("m");
               // gothitbymeteor = true;
               if(SearchLL(ular,temp) != NilLL)
               {
                    gothitbymeteor = true; 
                    if(indexOfLL(ular,temp) == 1)
                    {
                        can = false;

                    } 
                    DelP(&ular, temp);
               } 
            }else if(SearchLL(ular,temp) != NilLL)
            {
                // print dia elemen ke berapa;
                if(indexOfLL(ular, temp) == 1)
                {
                    printf("H");
                }else printf("%d",indexOfLL(ular,temp));
            }else
            {
                printf(" ");
            }

            printf(" ");
            if(i == 4) printf("\n");
            
            
        }
    }

    if(gothitbymeteor) printf("Anda terkena meteor! \n");
    else printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n");

    gothitbymeteor = false;
    printf("\n\n");
}

infotypeLL createrandominfotype()
{
    infotypeLL temp;
    srand(time(NULL));
    temp.x = rand() % 5;
    temp.y = rand() % 5;
    return temp;
}


int snakeonmeteor()
{
    initialize();

    
    printf("Selamat datang di snake on meteor!\n\n");
    printf("Mengenerate peta, snake dan makanan . . .\n\n");
    printf("Berhasil digenerate!\n\n");
    //int cnt = 0;
    
    while(can)
    {
        printsnake();
        // check apakah udah mati atau belum

        if(can)
        {
            printf("TURN %d:\n",turn);
            command = bacacommand();   
            
            while(!iscommandvalid(command))
            {
                printf("Command tidak valid! Silahkan input command menggunakan huruf W/A/S/D\n");
                command = bacacommand();      
            }

            turn++;
            before = command;
            
            makefood();
            makemeteor();
            move();
        }
    }    

}   
