#include <stdio.h>


struct praduct
{
   char name[200];
   float narx;
   int xajmi;
};

void view_proect(struct praduct arr[],int size);
void max(struct praduct arr[],int size);
void min(struct praduct arr[],int size);
void answer(struct praduct arr[],int num);
void check(float a);


int main()
{
  

  struct praduct praducts[]=
  {
     {"Pepsi 2l",15000,40},
     {"Pepsi 1l",12000,42},
     {"Qatiq",4000,50},
     {"Daftar",2000,54},
     {"Ruchka",1000,56},
     {"Tarvuz",23000,65},
     {"Qovun",24000,60},
     {"Olma",9000,82},
     {"Piyoz",4000,100},
     {"Un",10000,112},
     {"Shakar",12000,200},
     {"Gugurt",250,300},
     {"Tuxum",1500,250},
     {"Paypoq",5000,85},
     {"Naushnik simli",20000,22},
     {"Zaryadnik",15000,100},
     {"Pamildori",5000,100},
     {"Bodiring",5000,100}
  };
  
  int n=1;
  int len=sizeof(praducts)/sizeof(praducts[0]);
  
  while(n)
  {
      printf("|-----------------------------------------------------|\n");
      printf("|    Assalomu alaykum do'konimizga hush kelibsiz      |\n");
      printf("|-----------------------------------------------------|\n");
      printf("|  Maxsulotlar ro'yxatini ko'rish uchun 1 ni Bosing   |\n");
      printf("|  Eng qimmat maxsulot 2 ni Bosing                    |\n");
      printf("|  Eng arzon maxsulot 3 ni Bosing                     |\n");
      printf("|-----------------------------------------------------|\n\n");
     
      int a;
      
      printf(">>>>>> :");
      scanf("%d",&a);
    
          switch(a)
          {
           case 1:view_proect(praducts,len);break;
           case 2: max(praducts,len);break;
           case 3: min(praducts,len);break;
           default: printf("=======>>>>>>Error 404<<<<<<=====\n");break;
          }
             
              printf("\n\nYana nimadir hohlaysizmi ?\nAgar yana hohlasangiz 1 ni akis holda 0 ni kriting ");
              scanf("%d",&n);
  }

   return 0;
}


void view_proect(struct praduct arr[],int size)
{

  int a,c=1,t;
  float d=0;
  
   printf("|T/R|      Nomi     |      Narxi    | neshtaligi |\n");
  
   for(int i=0;i<size;i++)
   {
       printf("|%3i|%-15s|%15.2f|%12i|\n",i,arr[i].name,arr[i].narx,arr[i].xajmi);
   }
   
   while(c)
   {
    
     printf("Nima sotib olasiz tartib raqamini kriting \n>>>>>>> ");
     m:
     scanf("%d",&a);
     
     if(a>17){
       printf("Xato qayta kiritin \n");
       goto m;
     }
    
     printf("Neshta olasiz \n>>>>>> ");
     scanf("%d",&t);
    
     if(arr[a].xajmi>t)
     {
        d += t*arr[a].narx;
        arr[a].xajmi=arr[a].xajmi-t;
     }
     
     else{
      
          printf("Bizda buncha maxsulot yo'q \n Bizda %d ta maxsulot mavjut olasizmi \n",arr[a].xajmi);
          printf("Olsangiz 1ni bosing akisxolda 0 ni");
          scanf("%d",&c);
          
          if(c==0){
            return;
          }
         
          else {
             d += arr[a].xajmi * arr[a].narx;
          }
     }
     
     printf("Yana narsa olsangiz 1 ni bosing akis holda 0 ni\n>>>>> ");
     scanf("%d",&c);
   }

   check(d);

}


void max(struct praduct arr[],int size)
{
  struct praduct max=arr[0];
     for(int i=0;i<size;i++)
     {
       if(max.narx<arr[i].narx)
       {
          max=arr[i];
       }
     }
    printf("\nEng qimmat maxsulot ==|%-15s|%.2f|\n",max.name,max.narx);
}



void min(struct praduct arr[],int size)
{
    struct praduct min=arr[0];
      for(int i=0;i<size;i++)
      {
        if(min.narx>arr[i].narx)
        {
          min=arr[i];
        }
      }
     printf("\nEng arzon maxsulot ==|%-15s|%.2f|\n",min.name,min.narx);
}



void check(float a){
   
    float d;
    
    printf("\t\t|CHECK|\n");
    printf("|------------------------------|\n");
    printf("|%20.2f-So'm|\n",a);
    
    f:
    printf("Pulni to'lang ");
    scanf("%f",&d);

    if(a-d==0){
      printf("Harid uchun raxmat");
    }
    
    else if(d-a>0){
        printf("Qaytimingiz %.2f",a-d);
    }

    else{
      printf("Qayta to'lang ");
      goto f;
    }
}