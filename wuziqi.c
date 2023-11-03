#include <stdio.h>
void putpan(char a[15][15],int ROW,int COL);
int win(char a[15][15],int ROW,int COL);
int QZ(char a[15][15],int x,int y,int ROW,int COL);
int main(){                                   /*黑子为 “*”白子为 “#”*/ 
	int ROW=15;
	int COL=15;
	int i=0;
	int j=0;
	int count=0;
	int ret=0;
	int m=3;
	char board[15][15];
	for (i=0;i<ROW;i++)
	{
		for (j=0;j<COL;j++)
		{
			board[i][j] =' ';
		}
	}
	putpan(board,15,15);                  
	printf("\n");                              /*初始化及打印棋盘*/ 
	while(ret==0){
		m=3;
	    printf("黑子请输入坐标\n");
	    while(m!=2){
	        scanf("%d%d",&i,&j);
	        m=QZ(board,i,j,15,15);
	        if(m==0) {
    		    printf("超出棋盘范围，请重新输入\n");
    		    continue;
	        }
            if(m==1){
    		    printf("位置占用，请重新输入\n");
    		    continue;
         	}
    	    if(m==2){
    	        board[i-1][j-1]='*';
    	        break;
    	    }
        }
    	count++;
    	ret=win(board,15,15);
    	if(ret!=0){
    	    putpan(board,15,15);
    	    printf("\n");
    		break;
		}
	    printf("白子请输入坐标\n");
	    m=3;
    	while(m!=2){
	        scanf("%d%d",&i,&j);
	        m=QZ(board,i,j,15,15);
	        if(m==0) {
    		    printf("超出棋盘范围，请重新输入\n");
    		    continue;
	        }
            if(m==1){
    		    printf("位置占用，请重新输入\n");
    		    continue;
         	}
    	    if(m==2){
    	        board[i-1][j-1]='#';
    	        break;
    	    }
        }
    	count++;
    	ret=win(board,15,15);
    	if(ret!=0){
    		putpan(board,15,15);
    		printf("\n");
    		break;
		}  		                                                         /*落子及记录数量*/ 
		
	  	if(count>=224&&ret==0){
	  		ret=2;
		  }
		putpan(board,15,15);
		printf("\n");
    }
    
  	if(ret==-1){
  		printf("黑子胜");
	  }
	else if(ret==1){
		printf("白子胜");
	}
	else {
		printf("平局"); 
	}
	return 0;
}
	
/*函数体*/	
void putpan(char a[15][15],int ROW,int COL){
	int i=0;
	int j=0;
	for (i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			printf(" ---");
		}
		printf("\n");
		for(j=0;j<COL;j++){
			printf("| %c ",a[i][j]);
		}
		printf("|\n");
	}
	for(j=0;j<COL;j++){
			printf(" ---");
		}
}
int win(char a[15][15],int ROW,int COL){
	int i=0;
	int j=0;
	int N=0;
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			if(j<COL-4){
				if(a[i][j]!=' '&&a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2]&&a[i][j]==a[i][j+3]&&a[i][j]==a[i][j+4]){
					if(a[i][j]=='*'){
						return -1;
					}
					else{
						return 1;
					}	
				}
			}
			if(i<ROW-4){
				if(a[i][j]!=' '&&a[i][j]==a[i+1][j]&&a[i][j]==a[i+2][j]&&a[i][j]==a[i+3][j]&&a[i][j]==a[i+4][j]){
					if(a[i][j]=='*'){
						return -1;
					}
					else{
						return 1;
					}	
				}
			}
			if(i>=4&&j<COL-4){
				if(a[i][j]!=' '&&a[i][j]==a[i-1][j+1]&&a[i][j]==a[i-2][j+2]&&a[i][j]==a[i-3][j+3]&&a[i][j]==a[i-4][j+4]){
					if(a[i][j]=='*'){
						return -1;
					}
					else{
						return 1;
					}	
				}
			}
			if(i<ROW-4&&j<COL-4){
				if(a[i][j]!=' '&&a[i][j]==a[i+1][j+1]&&a[i][j]==a[i+2][j+2]&&a[i][j]==a[i+3][j+3]&&a[i][j]==a[i+4][j+4]){
					if(a[i][j]=='*'){
						return -1;
					}
					else{
						return 1;
					}	
				}
			}
		}
	}
	return 0;
}
int QZ(char a[15][15],int x,int y,int ROW,int COL){
	if(x>ROW||y>COL||x<=0||y<=0) {
    		return 0;
	    }
    if(a[x][y]!=' '){
    		return 1;
    	}
    else{
    	    return 2;
    	}
}
