package main;

public class Fibo {

	public static void main(String[] args) {

		System.out.println("Hello, World!");
		for(int i=0;i<60;i++) {
			System.out.println(i + " " +fiboInt(i));
		}
	}

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
		//Overflow produced at 24th value
	}

	long fiboLong(int n){

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
		//Overflow nor produced after a long time, stopped at 54th term
	}

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
		//Overflow nor produced after a long time, stopped at 54th term
	}
}
