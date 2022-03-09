import java.util.*;
import java.math.BigInteger;

class Diffie_Hellman
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Prime Number : ");
		int p=sc.nextInt();
		
		int g=primerootF(p);
		System.out.println("Choose 1st secret no(Alice)");
		int a=sc.nextInt();
		System.out.println("Choose 2nd secret no(BOB)");
		int b=sc.nextInt();
		
		int A = (int)Math.pow(g,a)%p;
		int B = (int)Math.pow(g,b)%p;
		
		int S_A = (int)Math.pow(B,a)%p;
		int S_B =(int)Math.pow(A,b)%p;	
		
		if(S_A==S_B)
		{
			System.out.println("ALice and Bob can communicate with each other!!!");
			System.out.println("They share a secret no = "+S_A);			
		}
		
		else
		{
			System.out.println("ALice and Bob cannot communicate with each other!!!");
		}
	}



     public static int primerootF(int p) {
        
        
        int m = p;
        if (isPrime(p)) {
            m = p - 1;
        }
        int primeRoot = 0;
        Map<Integer, Integer> primeFactor = getPrimeFactor(m);
        for (Map.Entry<Integer, Integer> map : primeFactor.entrySet()) {
            primeFactor.put(map.getKey(), m / map.getKey());
        }
        for (int i = 2; i <= m; i++) {
            boolean notPrimeRoot = false;
            Set<Integer> reminder = new HashSet<>();
            for (Map.Entry<Integer, Integer> map : primeFactor.entrySet()) {
                if(BigInteger.valueOf(i).modPow(BigInteger.valueOf(map.getValue()), BigInteger.valueOf(p)).equals(BigInteger.ONE))
                    notPrimeRoot = true;
            }
            if (!notPrimeRoot) {
                primeRoot = i;
                break;
            }
        }
        return primeRoot;
    }

    private static boolean isPrime(int p) {
        for (int i = 2; i <= Math.sqrt(p); i++) {
            if (p % i == 0) {
                return false;
            }
        }
        return true;
    }

    private static Map<Integer, Integer> getPrimeFactor(int p) {
        Map<Integer, Integer> map = new HashMap<>();
        while (p % 2 == 0) {
            insertToMap(2, map);
            p /= 2;
        }

        for (int i = 3; i <= Math.sqrt(p); i += 2) {
            while (p % i == 0) {
                insertToMap(i, map);
                p /= i;
            }
        }

        if (p > 2)
            insertToMap(p, map);
        return map;
    }

    private static void insertToMap(int i, Map<Integer, Integer> map) {
        if (map.get(i) != null) {
            map.put(i, map.get(i) + 1);
        } else {
            map.put(i, 1);
        }
    }
}











