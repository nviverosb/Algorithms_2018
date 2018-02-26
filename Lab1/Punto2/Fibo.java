package main;

public class Fibo {

	public static void main(String[] args) {

		System.out.println("Hello, World!");
		for(int i=0;i<60;i++) {
			System.out.println(i + " " +fiboLong(i));
		}
	}

	//Broke at the 47th term
	static int fiboInt(int n) {
		if(n == 0){
			return 0;
		}
		else if (n == 1)
		{
			return 1;
		}
		else
		{
			return(fiboInt(n - 1) + fiboInt(n - 2));
		}
	}

	//Broke at the 24th term
	static short fiboShort(int n){

		if(n == 0){
			return 0;
		}
		else if (n == 1)
		{
			return 1;
		}
		else
		{
			return (short) (fiboShort(n - 1) + fiboShort(n - 2));
		}
	}

	//After a long time, stopped at term 50, no overflow
	static long fiboLong(int n){

		if(n == 0){
			return 0;
		}
		else if (n == 1)
		{
			return 1;
		}
		else
		{
			return(fiboLong(n - 1) + fiboLong(n - 2));
		}
	}

	//After a long time, stopped at term 50, no overflow
	static long fiboLongLong(int n){

		if(n == 0){
			return 0;
		}
		else if (n == 1)
		{
			return 1;
		}
		else
		{
			return(fiboLongLong(n - 1) + fiboLongLong(n - 2));
		}
	}
}
