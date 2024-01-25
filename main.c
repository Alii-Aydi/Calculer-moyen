#include <stdio.h>
#include <stdlib.h>
#include <String.h>

struct matiere{
    char nom[20];
    char regim;
    int coff;
    float noteCC1;
    float noteCC2;
    float noteEx;
    float moyenne;
    float score;
};

int main()
{
    int checker,ch;
    int n=0,nbr=0;
    struct matiere m;
    float sumscores=0;
    float moyennegenerale=0;
    int sumcoffs=0;
    struct matiere*list=calloc(0,sizeof(struct matiere));
    while(ch!=6){
        system("cls");
        printf("\t\tMenu\n");
        printf("-----------------------------------\n");
        printf("1.Nouvelle notes\n");
        printf("2.Editer les notes\n");
        printf("3.Calculer et affichier\n");
        printf("4.Supprimer une note\n");
        printf("5.Supprimer tout\n");
        printf("6.Quiter\n");
        printf("\n");
        printf("Your choise : ");
        do{
            checker=scanf("%d",&ch);
            while(checker!=1){
                scanf("%*[^\n]");
                printf("Your choise : ");
                checker=scanf("%d",&ch);
            }
            }while(ch!=1&&ch!=2&&ch!=3&&ch!=4&&ch!=5&&ch!=6);
        if(ch==1){
            system("cls");
            inserer(&n,&m,list);
            printf("Insertion terminer !!\n");
            printf("Presser un cle pour retourner au menu...\n");
            getch();
        }else if(ch==2){
            system("cls");
            if(n==0){
                printf("Auccune note !!\n");
            }else{
                printf("Editer\n");
                printf("******\n");
                edit(list,&n,&m);
            }
            printf("Presser un cle pour retourner au menu...\n");
            getch();
        }else if(ch==3){
            system("cls");
            if(n==0){
                printf("Auccune note !!\n");
            }else{
                calcmoyennegenerale(&n,list,&sumscores,&moyennegenerale,&sumcoffs);
                aff(n,list,&moyennegenerale);
            }
            printf("Presser un cle pour retourner au menu...\n");
            getch();
        }else if(ch==4){
            system("cls");
            if(n==0){
                printf("Auccune note !!\n");
            }else{
                printf("Suprimer\n");
                printf("********\n");
                supp(list,&n);
                printf("Matiere supprimer !!\n");
            }
            printf("Presser un cle pour retourner au menu...\n");
            getch();
        }else if(ch==5){
            struct matiere*list=calloc(0,sizeof(struct matiere));
            n=0;
            list=realloc(list,n*sizeof(struct matiere));
            printf("\nTout a supprime !!");
            sleep(2);
        }else{
            printf("\n");
            printf("Mercie d utuliser notre program !");
            printf("\n");
            sleep(2);
            break;
        }
    }
    return 0;
}

void inserer(int*n,struct matiere*m,struct matiere*list){
    int checker,k,t;
    t=*n;
    printf("Inserer votre notes\n");
    printf("Regimes:(M)->Mixte||(C)->Controle\n");
    printf("----------------------------------\n");
    printf("Donner le nbre de matieres : ");
    do{
        checker=scanf("%d",&k);
        while(checker!=1){
            scanf("%*[^\n]");
            printf("Donner le nbre de matieres : ");
            checker=scanf("%d",&k);
        }
    }while(k<=0||k>20);
    list=realloc(list,(*n+k)*sizeof(struct matiere));
    for(int i=t;i<t+k;i++){
        printf("Nom matiere n %d : ",i+1);
        getchar();
        scanf("%[^\n]%*c",m->nom);
        printf("Regime : ");
        do{
            scanf("%c",&m->regim);
        }while(m->regim!='M'&&m->regim!='C'&&m->regim!='m'&&m->regim!='c');
        printf("Coff : ");
        do{
            checker=scanf("%d",&m->coff);
            while(checker!=1){
                scanf("%*[^\n]");
                printf("Coff : ");
                checker=scanf("%d",&m->coff);
            }
        }while(m->coff<=0 || m->coff>4);
        printf("NoteCC1 : ");
        do{
            scanf("%f",&m->noteCC1);
        }while(m->noteCC1<0 || m->noteCC1>20);
        printf("NoteCC2 : ");
        do{
            scanf("%f",&m->noteCC2);
        }while(m->noteCC2<0 || m->noteCC2>20);
        printf("NoteEx : ");
        do{
            scanf("%f",&m->noteEx);
        }while(m->noteEx<0 || m->noteEx>20);
        if(m->regim=='M'||m->regim=='m'){
            m->moyenne=m->noteCC1*0.1+m->noteCC2*0.2+m->noteEx*0.7;
            m->score=m->moyenne*m->coff;
        }else{
            m->moyenne=m->noteCC1*0.2+m->noteCC2*0.4+m->noteEx*0.4;
            m->score=m->moyenne*m->coff;
        }
        *(list+i)=*m;
        *n=*n+1;
    }
}

void calcmoyennegenerale(int*n,struct matiere*list,float*sumscores,float*moyennegenerale,int*sumcoffs){
    *sumscores=0;
    *sumcoffs=0;
    *moyennegenerale=0;
    for(int i=0;i<*n;i++){
        *sumscores=*sumscores+(list+i)->score;
        *sumcoffs=*sumcoffs+(list+i)->coff;
    }
    *moyennegenerale=*sumscores/(*sumcoffs);
}

void aff(int n,struct matiere*list,float*moyennegenerale){
    char reponse;
    char anne[20];
    int semester;
    printf("***************************************************\n");
    for(int i=0;i<n;i++){
        printf("%s : %2.2f  %2.2f  %2.2f  moy : %2.2f \n",(list+i)->nom,(list+i)->noteCC1,(list+i)->noteCC2,(list+i)->noteEx,(list+i)->moyenne);
    }
    printf("***************************************************\n");
    printf("\n");
    printf("Moyenne Generale : %2.2f\n",*moyennegenerale);
    printf("\n");
    printf("voulez vous une bultain de notes ?(Y/N): ");
    do{
        scanf("%c",&reponse);
    }while(reponse!='Y'&&reponse!='N'&&reponse!='y'&&reponse!='n');
    if(reponse=='Y'||reponse=='y'){
        printf("Donner l anne (premier/dexieme...) : ");
    scanf("%s",anne);
    printf("Semester (1 ou 2) : ");
    scanf("%d",&semester);
    FILE*Bultain=fopen("Bultain","w");
    fprintf(Bultain,"Bultain de Notes du %s anne semester %d :\n",anne,semester);
    fprintf(Bultain,"***************************************************\n");
    for(int i=0;i<n;i++){
        fprintf(Bultain,"%s : %2.2f  %2.2f  %2.2f  moy : %2.2f \n",(list+i)->nom,(list+i)->noteCC1,(list+i)->noteCC2,(list+i)->noteEx,(list+i)->moyenne);
    }
    fprintf(Bultain,"***************************************************\n");
    fprintf(Bultain,"\n");
    fprintf(Bultain,"Moyenne Generale : %2.2f\n",*moyennegenerale);
    fprintf(Bultain,"\n");
    fclose(Bultain);
    }
}

void edit(struct matiere*list,int*n,struct matiere*m){
    int pos,checker;
    printf("Nemero de la matiere : ");
    do{
        checker=scanf("%d",&pos);
        while(checker!=1){
            scanf("%*[^\n]");
            printf("Donner le nbre de matieres : ");
            checker=scanf("%d",&pos);
        }
    }while(pos<=0||pos>*n);
    printf("***************************************************\n");
    printf("Ancien donnes :\n");
    printf("Nom matiere n %d : %s\nRegime : %2.2c\nCoff : %d\nNoteCC1 : %2.2f\nNoteCC2 : %2.2f\nNoteEx : %2.2f\n",pos,(list+pos-1)->nom,(list+pos-1)->regim,(list+pos-1)->coff,(list+pos-1)->noteCC1,(list+pos-1)->noteCC2,(list+pos-1)->noteEx);
    printf("***************************************************\n");
    printf("Noveau donnes :\n");
    printf("Nom matiere n %d : ",pos);
    getchar();
    scanf("%[^\n]%*c",m->nom);
    printf("Regime : ");
    do{
        scanf("%c",&m->regim);
    }while(m->regim!='M'&&m->regim!='C'&&m->regim!='m'&&m->regim!='c');
    printf("Coff : ");
    do{
        checker=scanf("%d",&m->coff);
        while(checker!=1){
            scanf("%*[^\n]");
            printf("Coff : ");
            checker=scanf("%d",&m->coff);
        }
    }while(m->coff<=0 || m->coff>4);
    printf("NoteCC1 : ");
    do{
    scanf("%f",&m->noteCC1);
    }while(m->noteCC1<0 || m->noteCC1>20);
    printf("NoteCC2 : ");
    do{
        scanf("%f",&m->noteCC2);
    }while(m->noteCC2<0 || m->noteCC2>20);
    printf("NoteEx : ");
    do{
        scanf("%f",&m->noteEx);
    }while(m->noteEx<0 || m->noteEx>20);
    if(m->regim=='M'||m->regim=='m'){
        m->moyenne=m->noteCC1*0.1+m->noteCC2*0.2+m->noteEx*0.7;
        m->score=m->moyenne*m->coff;
    }else{
        m->moyenne=m->noteCC1*0.2+m->noteCC2*0.4+m->noteEx*0.4;
        m->score=m->moyenne*m->coff;
    }
    *(list+pos-1)=*m;
}

void supp(struct matiere*list,int*n){
    int pos,checker;
    printf("Nemero de la matiere : ");
    do{
        checker=scanf("%d",&pos);
        while(checker!=1){
            scanf("%*[^\n]");
            printf("Donner le nbre de matieres : ");
            checker=scanf("%d",&pos);
        }
    }while(pos<=0||pos>*n);
    pos--;
    for(int i=pos;i<*n;i++){
        *(list+i)=*(list+i+1);
    }
    *n=*n-1;
}
