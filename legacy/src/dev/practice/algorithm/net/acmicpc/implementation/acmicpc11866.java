package algorithm.net.acmicpc.implementation;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class acmicpc11866 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        List<Integer> list = new ArrayList<>(n);
        for ( int i = 1; i <= n; i++ ) list.add(i);

        int k = sc.nextInt(), loc = -1;
        System.out.printf("<");
        while( !list.isEmpty() ) {
            loc = (loc + k) % list.size();
            System.out.printf(
                    ( list.size() == 1 ) ? "%d" : "%d, ",
                    list.remove(loc--)
            );
        }
        System.out.printf(">");
    }
}
