#include "parseur.h"

int parser(Token** tokens, int* tokenNB, Expression* expression){
    if(*tokenNB<3){
        return 1;
    }
    for(int i=0; i<3; i++){
        Token cur_token=(*tokens)[i];
        if((cur_token.type==0 && (i==0 || i==2)) || (cur_token.type!=0 && i==1)){
            return 1;
        }
        else{
            switch(i){
                case 0:
                    expression->operande1=cur_token;
                    break;
                case 1:
                    expression->operation=cur_token;
                    break;
                case 2:
                    expression->operande2=cur_token;
            }
        }
    }
    return 0;
}