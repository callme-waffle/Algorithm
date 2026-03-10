package algorithm.net.acmicpc.implementation;
//
//import java.util.ArrayList;
//import java.util.List;
//import java.util.Scanner;
//
//public class acmicpc2563 {
//    static class Paper {
//        public int sx;
//        public int ex;
//        public int sy;
//        public int ey;
//
//        public Paper( int sx, int sy ) {
//            this.sx = sx;
//            this.sy = sy;
//            this.ex = sx + 10;
//            this.ey = sy + 10;
//        }
//
//        public static int getOverlapArea( Paper a, Paper b ) {
//            // x 미중복 예외처리
//            if ( a.ex < b.sx || b.ex < a.sx ) return 0;
//            // y 미중복 예외처리
//            if ( a.ey < b.sy || b.ey < a.sy ) return 0;
//
//            int x_diff = a.ex - b.sx;
//            if ( !( 0 < x_diff && x_diff < 10 ) ) x_diff = b.ex - a.sx;
//
//            int y_diff = a.ey - b.sy;
//            if ( !( 0 < y_diff && y_diff < 10 ) ) y_diff = b.ey - a.sy;
//
//            System.out.printf("a: %d~%d,%d~%d / b: %d~%d,%d~%d / x: %d / y: %d\n", a.sx, a.ex, a.sy, a.ey, b.sx, b.ex, b.sy, b.ey, x_diff, y_diff);
//
//            return x_diff * y_diff;
//        }
//    }
//    public static void main(String[] args) {
//        Scanner sc = new Scanner( System.in );
//
//        int cnt = sc.nextInt();
//        int area = cnt * ( 10 * 10 );
//
//        Paper[] papers = new Paper[ cnt ];
//        for ( int i = 0; i < cnt; i++ ) {
//            papers[i] = new Paper( sc.nextInt(), sc.nextInt() );
//        }
//        for ( int i = 0; i < cnt; i++ ) {
//            for ( int j = i+1; j < cnt; j++ ) {
//                area -= Paper.getOverlapArea( papers[i], papers[j] );
//            }
//        }
//
//        System.out.println( area );
//    }
//}

import java.util.Arrays;
import java.util.Scanner;

public class acmicpc2563 {
    public static void main(String[] args) {
        Scanner sc = new Scanner( System.in );

        int cnt = sc.nextInt();
        int[][] paper = new int[100][100];
        for ( int[] p: paper ) Arrays.fill( p, 0 );

        for ( int i = 0; i < cnt; i++ ) {
            int sx = sc.nextInt();
            int sy = sc.nextInt();

            for ( int j = sx; j < sx + 10; j++ )
                for ( int k = sy; k < sy + 10; k++ )
                    paper[k][j] = 1;
        }

        int s = 0;
        for ( int i = 0; i < 100; i++ )
            for ( int j = 0; j < 100; j++ )
                s += paper[i][j];

        System.out.println( s );
    }
}
