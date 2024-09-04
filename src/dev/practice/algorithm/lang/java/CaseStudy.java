package algorithm.lang.java;

import java.util.Scanner;

public class CaseStudy {
    public static void main(String[] args) {
        // 조건문 (Case Statements)

        // 1. if
        Scanner s1 = new Scanner( System.in );
        int a1 = s1.nextInt();
        if ( a1 == 1 ) System.out.println( "[if] value is: 1" );
        else if ( a1 == 2 ) System.out.println( "[if] value is: 2" );
        else if ( a1 == 3 ) System.out.println( "[if] value is: 3" );
        else if ( a1 == 4 ) System.out.println( "[if] value is: 4" );
        else if ( a1 == 5 ) System.out.println( "[if] value is: 5" );
        else System.out.println( "[if] value is unknown" );

        // 2. switch - case
        switch( a1 ) {
            default:
                System.out.printf("[switch] value is: ");
                // break가 없는경우 break가 있는 case까지 계속 fall하며 실행
                // (조건에 맞지 않아도 case를 고려하지 않고 계속 실행)
            case 1:
                System.out.println("1");
                break;
            case 2: { // 코드블록 영역지정가능
                System.out.println("2");
                break;
            }
            case 3:
                System.out.println("3");
                break;
            case 4:
                System.out.println("4");
                break;
            case 5:
                System.out.println("5");
                break;
        }

        // 3. 삼항연산자
        System.out.printf("[삼항연산] value is %s\n", a1 == 1 ? "1" : "not 1" );
    }
}
