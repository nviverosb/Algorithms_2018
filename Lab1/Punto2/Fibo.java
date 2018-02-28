import java.math.BigInteger;

public class Fibo {

	public static void main(String[] args) {

		//System.out.println("Hello, World!");
		for(int i=0;i<10000;i++) {
			System.out.println(i + " " +fiboLongLong(i));
		}
	}

	//Overflow at the 47th term
	static int fiboInt(int n){

	    int a=0,b=1,fibonacci;
	    do{
	        fibonacci=a+b;
	        a=b;
	        b=fibonacci;
	        n--;
	    }while(n>1);
	    return fibonacci;
	}

	//Overflow at the 24th term
	static short fiboShort(int n){

	    short a=0,b=1,fibonacci;
	    do{
	        fibonacci= (short) (a+b);
	        a=b;
	        b=fibonacci;
	        n--;
	    }while(n>1);
	    return fibonacci;
	}

	//Overflow at the 24th term
	static long fiboLong(int n){

	    long a=0,b=1,fibonacci;
	    do{
	        fibonacci=a+b;
	        a=b;
	        b=fibonacci;
	        n--;
	    }while(n>1);
	    return fibonacci;
	}

	//No overflow produced at the 10000th term
	static BigInteger fiboLongLong(int n){

		BigInteger a = BigInteger.valueOf(0);
		BigInteger b = BigInteger.valueOf(1);
	    BigInteger fibonacci = BigInteger.valueOf(0);
	    do{
	        fibonacci = a.add(b);
	        a=b;
	        b=fibonacci;
	        n--;
	    }while(n>1);
	    return fibonacci;
	}
}
