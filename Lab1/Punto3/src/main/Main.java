package main;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;

public class Main {

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException{
		
		double[] tamanos = new double[500];
		double[] arreglo = new double[2];
		for(int i=0;i<500;i++) {
			tamanos[i] = multMatrices(i);
		}
		
		//This part of the code was taken from https://stackoverflow.com/questions/2885173/how-do-i-create-a-file-and-write-to-it-in-java
		PrintWriter writer = new PrintWriter("/Users/nicolas/Documents/LocalRepos/Algorithms/Algorithms_2018/Lab1/Punto3/matricesJava.dat", "UTF-8");
		for(int i=0;i<500;i++) {
			
			writer.print(i+1 + " ");
			writer.printf("%.10f \n", tamanos[i]);
		}
		
		writer.close();
	}
	
	private static double multMatrices(int n){
		
		int[][] matrizA = new int[n][n];
		int[][] matrizB = new int[n][n];
		int[][] resultados = new int[n][n];
		int numeroDeInstrucciones = 2*n*n*n - n*n;;
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				matrizA[i][j] = 1;
				matrizB[i][j] = 2;
				matrizA[i][j] = 0;
			}
		}
		
		double time = System.nanoTime();
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				for(int k=0;k<n;k++) {
					resultados[i][j] += matrizA[i][k] * matrizB[k][j];
				}
			}
		}
		
		time = System.nanoTime() - time;
		
		return time/numeroDeInstrucciones;
	}
}
