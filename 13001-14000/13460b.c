
			{
				printf("%d====", rc);
				for(int i = 0; i < n; i ++){
					for(int j = 0; j < m; j ++){
						if(rx == i && ry == j){
							printf("r");
						}
						
						else if(rnx == i && rny == j){
							printf("R");
						}
						else if(bx == i && by == j){
							printf("b");
						}
						else if(bnx == i && bny == j){
							printf("B");
						}
						else{
							printf("%c", map[i][j]);
						}
					}
					printf("\n");
				}
			}
