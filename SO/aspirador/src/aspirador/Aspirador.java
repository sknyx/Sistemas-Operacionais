package aspirador;

import java.util.Random;

public class Aspirador {

public static void main(String[] args) throws InterruptedException {

	int[][] matriz=new int[5][5];
	Random num = new Random();
	int cont = 0;
	System.out.print("-- Estado inicial dos c�modos--\n");
	for (int i=0; i< 5; i++){  //
		System.out.println();
		for (int j=0; j<5; j++){
			matriz[i][j]=num.nextInt(100);
			if (matriz[i][j]%2==0){  //se num � par preenche c�modo com 0
				matriz[i][j]=0;
			}
			else 
			{
				matriz[i][j]=1;
			}
		   System.out.print("["+matriz[i][j]+"]"); //exibe todos os c�modos
		}
	}
	System.out.print("\n \n-- Executando a limpeza -- \n");
	Thread.sleep(2500);

	//Inicio da limpeza

	for (int i=0; i< 5; i++){
		System.out.println();
		for (int j=0; j<5; j++){
		   if (matriz[i][j]==1){ //se for 1 esta sujo ent�o limpa e soma ao contador
				matriz[i][j]=0;
				cont++;
			}
		   System.out.print("["+matriz[i][j]+"]");
			Thread.sleep(1000);
		}
	}


	//Final da limpeza

	System.out.println();
	int custo = (cont *5) - (50 - cont); //c�lculo do custo
	System.out.println("\nLimpeza conclu�da, custo total: "+custo+"\n");

	}
}