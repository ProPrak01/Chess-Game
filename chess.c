#include <stdio.h>
#include <stdlib.h>

void showpositions(int **pawn){
    printf("       0    1     2    3    4    5    6    7\n");
    printf("-----------------------------------------------\n");

    for (int i=0;i<8;i++){
        for(int j =0 ;j<8;j++)
        {
            if(j==0){
                printf("%d   |",i);
            }
            printf(" %d ",*(*(pawn+i)+j));
        }
        printf("\n    |\n");
    }
}
void position_of_an_id(int **pawn,int* h,int* k,int id){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if (*(*(pawn+i)+j)==id){
                *h=i;
                *k=j;
            }
        }
    }
}
void id_at_position(int **pawn,int *h,int *k,int *piece){
    *piece = *(*(pawn+(*h))+(*k));

}
void askposition(int *h, int *k){
    printf("where to move in y coordinate? ");
    scanf("%d",h);
    printf("where to move in x coordinate?");
    scanf("%d",k);
}
void resetpositions(int **pawn){
    for (int i=2;i<6;i++){
        for(int j =0 ;j<8;j++)
        {
            *(*(pawn+i)+j) = 888;
          
        }
 
    }
    for(int j=0;j<8;j++){
        *(*(pawn+1)+j) = 51*10+j;
        *(*(pawn+6)+j)=91*10 +j;
        
    }
    *(*(pawn+0)+0) =520;
    *(*(pawn+0)+7) = 521;
    *(*(pawn+0)+1) = 530;
    *(*(pawn+0)+6)= 531;
    *(*(pawn+0)+2) = 540;
    *(*(pawn+0)+5) = 541;
    *(*(pawn+0)+3)  = 550;
    *(*(pawn+0)+4) = 560;

    *(*(pawn+7)+0) =920;
    *(*(pawn+7)+7) = 921;
    *(*(pawn+7)+1) = 930;
    *(*(pawn+7)+6)= 931;
    *(*(pawn+7)+2) = 940;
    *(*(pawn+7)+5) = 941;
    *(*(pawn+7)+3)  = 950;
    *(*(pawn+7)+4) = 960;

   

    
   
}
int pawnhinderance(int **pawn,int *x,int*y,int*p,int*q){
    int s=0;
    int color = (*(*(pawn+(*x))+(*y)))/100;
    if (color == 5){
        if(*(*(pawn+(*p)-1)+(*q)) != 888 ){
            s=1;
        }
        
        
    }
    else if (color == 9){
        if(*(*(pawn+(*p)+1)+(*q)) != 888 ){
            s=1;
        }
    }
    return s;
}
int rookhinderance(int **pawn,int *x,int*y,int*p,int*q){
    
    int s=0;
    int color = (*(*(pawn+(*x))+(*y)))/100;
    if (color == 5){
        if(*q ==*y){
            if(p > x){
                for(int i=*x;i<*p;i++){
                    if (*(*(pawn+i)+*q) != 888){
                        s=1;
                    }
                }
            }
            else if (p<x){
                for(int i=*x;i>*p;i--){
                    if (*(*(pawn+i)+*q) != 888 ){
                        s=1;
                    }
                    
                }
            }
        }
        else if(*p == *x){
            if(q > y){
                for(int i=*y;i<*q;i++){
                    if (*(*(pawn+*p)+i) != 888){
                        s=1;
                    }
                }
            }
            else if (q<y){
                for(int i=*y;i>*q;i--){
                    if (*(*(pawn+*p)+i) != 888){
                        s=1;
                    }
                    
                }
            }
        }
        
        
        
    }
    else if (color == 9){
        if(*q ==*y){
            if(p > x){
                for(int i=*x+1;i<*p;i++){
                    if (*(*(pawn+i)+*q) != 888 ){
                        s=1;
                    }
                }
            }
            else if (p<x){
                for(int i=*x-1;i>*p;i--){
                    if (*(*(pawn+i)+*q) != 888 ){
                        s=1;
                    }
                    
                }
            }
        }
        else if(*p == *x){
            if(q > y){
                for(int i=*y+1;i<*q;i++){
                    if (*(*(pawn+*p)+i) != 888){
                        s=1;
                    }
                }
            }
            else if (q<y){
                for(int i=*y-1;i>*q;i--){
                    if (*(*(pawn+*p)+i) != 888 ){
                        s=1;
                    }
                    
                }
            }
        }
        
        
    }
    return s;
}
int bishophinderance(int **pawn,int *x,int*y,int*p,int*q){
    int s=0;
    int color = (*(*(pawn+(*x))+(*y)))/100;
    if (color == 5){
        if(p>x && q>y){
            for(int i=*x+1;i<*p;i++){
                int j=i-(*x-*y);
                if(*(*(pawn+i)+j) != 888 ){
                    s=1;
                }
            }
        }
        else if(p>x && q<y){
            for(int i=*x+1;i<*p;i++){
                int j=(*x+*y)-i;
                if(*(*(pawn+i)+j) != 888){
                    s=1;
                }
            }
            
        }
        else if(p<x && q<y){
            for(int i=*x-1;i>*p;i--){
                int j=i-(*x-*y);
                if(*(*(pawn+i)+j) != 888 ){
                    s=1;
                }
            }
            
            
        }
        else if(p<x && q>y){
            for(int i=*x-1;i>*p;i--){
                int j=(*x+*y)-i;
                if(*(*(pawn+i)+j) != 888){
                    s=1;
                }
            }
            
            
        }
    }
        else if (color == 9){
            if(p>x && q>y){
                for(int i=*x+1;i<*p;i++){
                    int j=i-(*x-*y);
                    if(*(*(pawn+i)+j) != 888){
                        s=1;
                    }
                }
            }
            else if(p>x && q<y){
                for(int i=*x+1;i<*p;i++){
                    int j=(*x+*y)-i;
                    if(*(*(pawn+i)+j) != 888){
                        s=1;
                    }
                }
                
            }
            else if(p<x && q<y){
                for(int i=*x-1;i>*p;i--){
                    int j=i-(*x-*y);
                    if(*(*(pawn+i)+j) != 888 ){
                        s=1;
                    }
                }
                
                
            }
            else if(p<x && q>y){
                for(int i=*x-1;i>*p;i--){
                    int j=(*x+*y)-i;
                    if(*(*(pawn+i)+j) != 888 ){
                        s=1;
                    }
                }
                
                
            }
        }
        

       
    
    return s;
}
/*int kinghinderance(int **pawn,int *x,int*y,int*p,int*q){
    int s=0;
    int color = (*(*(pawn+(*x))+(*y)))/100;
    if (color == 5){
        if(){
            s=1;
        }
        
        
    }
    else if (color == 9){
        if(*(*(pawn+(*p))+(*q)) != 888 && (*(*(pawn+(*p))+(*q)))/100 == 9){
            s=1;
        }
    }
    return s;
}
 */
int queenhinderance(int **pawn,int *x,int*y,int*p,int*q){
    int s=0;
    int color = (*(*(pawn+(*x))+(*y)))/100;
    if (color == 5){
        if(*q ==*y){
            if(p > x){
                for(int i=*x;i<*p;i++){
                    if (*(*(pawn+i)+*q) != 888 ){
                        s=1;
                    }
                }
            }
            else if (p<x){
                for(int i=*x;i>*p;i--){
                    if (*(*(pawn+i)+*q) != 888 ){
                        s=1;
                    }
                    
                }
            }
        }
        else if(*p == *x){
            if(q > y){
                for(int i=*y;i<*q;i++){
                    if (*(*(pawn+*p)+i) != 888 ){
                        s=1;
                    }
                }
            }
            else if (q<y){
                for(int i=*y;i>*q;i--){
                    if (*(*(pawn+*p)+i) != 888){
                        s=1;
                    }
                    
                }
            }
        }
        if(p>x && q>y){
            for(int i=*x+1;i<*p;i++){
                int j=i-(*x-*y);
                if(*(*(pawn+i)+j) != 888 ){
                    s=1;
                }
            }
        }
        else if(p>x && q<y){
            for(int i=*x+1;i<*p;i++){
                int j=(*x+*y)-i;
                if(*(*(pawn+i)+j) != 888 ){
                    s=1;
                }
            }
            
        }
        else if(p<x && q<y){
            for(int i=*x-1;i>*p;i--){
                int j=i-(*x-*y);
                if(*(*(pawn+i)+j) != 888){
                    s=1;
                }
            }
            
            
        }
        else if(p<x && q>y){
            for(int i=*x-1;i>*p;i--){
                int j=(*x+*y)-i;
                if(*(*(pawn+i)+j) != 888){
                    s=1;
                }
            }
            
            
        }
        
        
    }
    else if (color == 9){
        if(*q ==*y){
            if(p > x){
                for(int i=*x;i<*p;i++){
                    if (*(*(pawn+i)+*q) != 888 ){
                        s=1;
                    }
                }
            }
            else if (p<x){
                for(int i=*x;i>*p;i--){
                    if (*(*(pawn+i)+*q) != 888 ){
                        s=1;
                    }
                    
                }
            }
        }
        else if(*p == *x){
            if(q > y){
                for(int i=*y;i<*q;i++){
                    if (*(*(pawn+*p)+i) != 888 ){
                        s=1;
                    }
                }
            }
            else if (q<y){
                for(int i=*y;i>*q;i--){
                    if (*(*(pawn+*p)+i) != 888 ){
                        s=1;
                    }
                    
                }
            }
        }
        else if(p>x && q>y){
            for(int i=*x+1;i<=*p;i++){
                int j=i-(*x-*y);
                if(*(*(pawn+i)+j) != 888 ){
                    s=1;
                }
            }
        }
        else if(p>x && q<y){
            for(int i=*x+1;i<=*p;i++){
                int j=(*x+*y)-i;
                if(*(*(pawn+i)+j) != 888 ){
                    s=1;
                }
            }
            
        }
        else if(p<x && q<y){
            for(int i=*x-1;i>*p;i--){
                int j=i-(*x-*y);
                if(*(*(pawn+i)+j) != 888 ){
                    s=1;
                }
            }
            
            
        }
        else if(p<x && q>y){
            for(int i=*x-1;i>*p;i--){
                int j=(*x+*y)-i;
                if(*(*(pawn+i)+j) != 888 ){
                    s=1;
                }
            }
            
            
        }
        
       
        
    }
    
    return s;
}
void whitepawn(int **pawn,int *k,int wpid){
        int x,y,p,q;
        position_of_an_id(pawn, &x, &y, wpid);
        askposition(&p,&q);
    int s = pawnhinderance(pawn,&x,&y,&p,&q);
    if(p==x+1 && q == y){
                if(*(*(pawn+p)+q) == 888 ){
                    *(*(pawn+p)+q) = wpid;
                    *(*(pawn+x)+y) = 888;
                *k=1;
            }
            
            else{
                printf("wrong move!! try again");
                *k=0;
            }
            
    }
    else if(p==x+2 && q==y && x==1 && s==0){
        if(*(*(pawn+p)+q) == 888 ){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        
        else{
            printf("wrong move!! try again");
            *k=0;
        }
    }
    else if(p==x+1 && (q==y+1 || q == y-1) && (*(*(pawn+p)+q)/100==9)){
        *(*(pawn+p)+q) = wpid;
        *(*(pawn+x)+y) = 888;
        *k=1;
    }
    
    else{
            printf("wrong move!! try again");
            *k=0;
    }
        
}
void blackpawn(int **pawn,int *k,int wpid){
        int x,y,p,q;
        position_of_an_id(pawn, &x, &y, wpid);
    
        askposition(&p,&q);
    int s = pawnhinderance(pawn,&x,&y,&p,&q);
        if(p==x-1 && q == y){
            if(*(*(pawn+p)+q) == 888 ){
                *(*(pawn+p)+q) = wpid;
                *(*(pawn+x)+y) = 888;
            *k=1;
        }
        
        else{
            printf("wrong move!! try again");
            *k=0;
        }
        
}
else if(p==x-2 && q==y && s==0 && x==6){
    if(*(*(pawn+p)+q) == 888 ){
        *(*(pawn+p)+q) = wpid;
        *(*(pawn+x)+y) = 888;
        *k=1;
    }
    
    else{
        printf("wrong move!! try again");
        *k=0;
    }
}
else if(p==x-1 && (q==y+1 || q == y-1) && (*(*(pawn+p)+q)/100==5)){
    *(*(pawn+p)+q) = wpid;
    *(*(pawn+x)+y) = 888;
    *k=1;
}
        else{
            printf("wrong move!! try again");
            *k=0;
        }
        
}
void whiterook(int **pawn,int *k,int wpid){
    int x,y,p,q,s;
    position_of_an_id(pawn, &x, &y, wpid);
    askposition(&p,&q);
    s = rookhinderance(pawn, &x, &y, &p, &q);
    if(((p==x) ^ (q == y)) && s==0){
        if(*(*(pawn+p)+q) == 888){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else if(*(*(pawn+p)+q)/100 == 9){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else{
            printf("wrong move!! try again");
            *k=0;

        }


    }
    else{
            printf("wrong move!! try again");
            *k=0;
        } 
}
void blackrook(int **pawn,int *k,int wpid){
    int x,y,p,q,s;
    position_of_an_id(pawn, &x, &y, wpid);
    askposition(&p,&q);
    s = rookhinderance(pawn, &x, &y, &p, &q);
    if(((p==x) ^ (q == y)) && s==0){
        if(*(*(pawn+p)+q) == 888){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else if(*(*(pawn+p)+q)/100 == 5){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else{
            printf("wrong move!! try again");
            *k=0;

        }


    }
    else{
            printf("wrong move!! try again");
            *k=0;
        } 
}
void whiteknight(int **pawn,int *k,int wpid){
 int x,y,p,q;
    position_of_an_id(pawn, &x, &y, wpid);
    askposition(&p,&q);
    if((p==x-1 && q==y-2) || (p==x-2 && q == y-1)|| (p == x-2 && q==y+1) 
    || (p==x-1 && q==y+2)||(p==x+1 && q== y+2)||(p==x+2 && q == y+1)
    ||(p==x+1 && q==y-2)||(p==x+2 && q==y-1)){
        if(*(*(pawn+p)+q) == 888){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else if(*(*(pawn+p)+q)/100 == 9){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else{
            printf("wrong move!! try again");
            *k=0;

        }


    }
    else{
            printf("wrong move!! try again");
            *k=0;
        } 
}   
void blacknight(int **pawn,int *k,int wpid){
 int x,y,p,q;
    position_of_an_id(pawn, &x, &y, wpid);
    askposition(&p,&q);
    if((p==x-1 && q==y-2) || (p==x-2 && q == y-1)|| (p == x-2 && q==y+1) 
    || (p==x-1 && q==y+2)||(p==x+1 && q== y+2)||(p==x+2 && y == y+1)
    ||(p==x+1 && q==y-2)||(p==x+2 && q==y-1)){
        if(*(*(pawn+p)+q) == 888){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else if(*(*(pawn+p)+q)/100 == 5){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else{
            printf("wrong move!! try again");
            *k=0;

        }


    }
    else{
            printf("wrong move!! try again");
            *k=0;
        } 
}
void whitebishop(int **pawn,int *k,int wpid){
    int x,y,p,q,s;
    position_of_an_id(pawn, &x, &y, wpid);
    askposition(&p,&q);
    s = bishophinderance(pawn,&x,&y,&p,&q);
    if(((x-y == p-q)^(x+y == p+q)) && s==0){
        if(*(*(pawn+p)+q) == 888){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else if(*(*(pawn+p)+q)/100 == 9){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else{
            printf("wrong move!! try again");
            *k=0;

        }


    }
    else{
            printf("wrong move!! try again");
            *k=0;
        } 

}
void blackbishop(int **pawn,int *k,int wpid){
    int x,y,p,q,s;
    position_of_an_id(pawn, &x, &y, wpid);
    askposition(&p,&q);
    s = bishophinderance(pawn,&x,&y,&p,&q);
    if(((x-y == p-q)^(x+y == p+q)) && s==0){
        if(*(*(pawn+p)+q) == 888){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else if(*(*(pawn+p)+q)/100 == 9){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else{
            printf("wrong move!! try again");
            *k=0;

        }


    }
    else{
            printf("wrong move!! try again");
            *k=0;
        } 

}
void whiteking(int **pawn,int *k,int wpid){
    int x,y,p,q;
    position_of_an_id(pawn, &x, &y, wpid);
    askposition(&p,&q);
    if((p>=x-1) && (p <= x+1) && (q <= y+1) && (q >= y-1)){
        if(*(*(pawn+p)+q) == 888){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else if(*(*(pawn+p)+q)/100 == 5){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else{
            printf("wrong move!! try again");
            *k=0;

        }


    }
    else{
            printf("wrong move!! try again");
            *k=0;
        }

    
    
}
void blackking(int **pawn,int *k,int wpid){
    int x,y,p,q;
    position_of_an_id(pawn, &x, &y, wpid);
    askposition(&p,&q);
    if((p>=x-1) && (p <= x+1) && (q <= y+1) && (q >= y-1)){
        if(*(*(pawn+p)+q) == 888){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else if(*(*(pawn+p)+q)/100 == 5){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else{
            printf("wrong move!! try again");
            *k=0;

        }


    }
    else{
            printf("wrong move!! try again");
            *k=0;
        }

}
void whitequeen(int **pawn,int *k,int wpid){
    int x,y,p,q,s;
    position_of_an_id(pawn, &x, &y, wpid);
    askposition(&p,&q);
    s = queenhinderance(pawn,&x,&y,&p,&q);
    if((((x-y == p-q)^(x+y == p+q)) ||( (p==x) || (q == y))) && s==0){
        if(*(*(pawn+p)+q) == 888){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else if(*(*(pawn+p)+q)/100 == 9){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else{
            printf("wrong move!! try again");
            *k=0;

        }


    }
    else{
            printf("wrong move!! try again");
            *k=0;
        }

    
    
}
void blackqueen(int **pawn,int *k,int wpid){
    int x,y,p,q,s;
    position_of_an_id(pawn, &x, &y, wpid);
    askposition(&p,&q);
    s = queenhinderance(pawn,&x,&y,&p,&q);
    if((((x-y == p-q)^(x+y == p+q)) ||( (p==x) || (q == y))) && s==0){
        if(*(*(pawn+p)+q) == 888){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else if(*(*(pawn+p)+q)/100 == 5){
            *(*(pawn+p)+q) = wpid;
            *(*(pawn+x)+y) = 888;
            *k=1;
        }
        else{
            printf("wrong move!! try again");
            *k=0;

        }


    }
    else{
            printf("wrong move!! try again");
            *k=0;
        }

    
    
}
int winwhite(int **pawn){
    int p=0;
    for(int i =0;i<8;i++){
        for(int j=0;j<8;j++){
            
            if (*(*(pawn+i)+j) == 950){
                p=1;
                break;
            }
            
        }
        if(p==1){
            break;
        }
    }
    return p;
}
int winblack(int **pawn){
    int q=0;
    for(int i =0;i<8;i++){
        for(int j=0;j<8;j++){
            
            if (*(*(pawn+i)+j) == 550){
                q=1;
                break;
            }
            
        }
        if(q==1){
            break;
        }
    }
    return q;
}
int main(){
    int **position_pawn = (int **)malloc(8 *sizeof(int *));
    for (int i = 0; i < 8; i++) {
        position_pawn[i] = (int *)malloc(8*sizeof(int));
    }
    printf("\n TUTORIAL:\n");
    printf("\n'888'-> represent blank,\n");
    printf("'520'-> hundread element represnt colour:5=white and 9=black\n");
    printf("     -> tenth element represent type of piece: 1.pawn, 2.rook, 3.knight,4.bishop, 5.king,6.queen\n");
    printf("     -> last digit represent the serial number of a perticular pawn ie. 0,1,2,3\n");
    printf("    i: verticla distance from top\n");
    printf("    j:horizontal distance from left\n");
    printf("----------------------------------------------------------------------------------\n\n\n");

    resetpositions(position_pawn);
    showpositions(position_pawn);
    int playagain=1;
    while(playagain==1){
        int turn,win=0,p=0,q=0;
        printf("\n which colour want to move first:(white->0 or black->1)");
        scanf("%d",&turn);
        while(win == 0){
            if(turn == 0){
                printf("\nit's white turn\n");
                int piecew;
                turn =1;
                int k=0;
                while(k==0){
                    printf("please select a piece");
                    scanf("%d",&piecew);
                    if (piecew == 510 || piecew == 511|| piecew == 512|| piecew == 513|| piecew == 514|| piecew == 515|| piecew == 515|| piecew == 516 ){
                        
                        whitepawn(position_pawn,&k,piecew);
                    }
                    else if(piecew == 520 || piecew == 521 ){
                        whiterook(position_pawn,&k,piecew);
                        
                    }
                    
                    else if(piecew == 530 || piecew == 531 ){
                        whiteknight(position_pawn,&k,piecew);
                        
                    }
                    else if(piecew == 540 || piecew == 541){
                        whitebishop(position_pawn,&k,piecew);
                    }
                    else if(piecew == 550){
                        whiteking(position_pawn,&k,piecew);
                    }
                    else if(piecew == 560){
                        whitequeen(position_pawn,&k,piecew);
                    }
                    
                }
                
                showpositions(position_pawn);
                p = winwhite(position_pawn);
                q=  winblack(position_pawn);
                if (p==0 || q== 0){
                    win =1;
                }
            }
            
            
            else if(turn== 1){
                printf("\nit's black turn\n");
                int pieceb;
                turn =0;
                //  int choose_piece = 0;
                int k=0;
                while(k==0){
                    printf("please select a piece");
                    scanf("%d",&pieceb);
                    if (pieceb == 910 || pieceb == 911|| pieceb == 912|| pieceb == 913|| pieceb == 914|| pieceb == 915|| pieceb == 915|| pieceb == 916 || pieceb == 917){
                        
                        blackpawn(position_pawn,&k,pieceb);
                    }
                    else if(pieceb == 920 || pieceb == 921 ){
                        blackrook(position_pawn,&k,pieceb);
                        
                    }
                    else if(pieceb == 930 || pieceb == 931 ){
                        blacknight(position_pawn,&k,pieceb);
                        
                    }
                    else if(pieceb == 940 || pieceb == 941){
                        blackbishop(position_pawn, &k, pieceb);
                    }
                    else if(pieceb == 950 ){
                        blackking(position_pawn, &k, pieceb);
                    }
                    else if(pieceb == 960 ){
                        blackqueen(position_pawn, &k, pieceb);
                    }
                    
                }
                showpositions(position_pawn);
                p = winwhite(position_pawn);
                q=  winblack(position_pawn);
                if (p==0 || q== 0){
                    win =1;
                }
                
            }
            
            
        }
        if(p==0){
            printf("\nWHITE WON THE GAME\n");
        }
        else if(q==0){
            printf("\nBLACK WON THE GAME\n");
        }
        printf("\nWant to play again?(Yes-1 , No-0)  ->");
        scanf("%d",&playagain);
    }
   
}
