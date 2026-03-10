package algorithm.net.acmicpc.implementation;

import java.util.*;
import java.util.Scanner;

public class acmicpc7568 {

    static class Person {
        public int w;
        public int h;

        public Person( int w, int h ) {
            this.w = w;
            this.h = h;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner( System.in );
        int n = sc.nextInt();

        List<Person> people = new ArrayList<>();
        for ( int i = 0; i < n; i++ ) {
            int w = sc.nextInt();
            int h = sc.nextInt();

            people.add( new Person( w, h ) );
        }

        for ( int i = 0; i < people.size(); i++ ) {
            Person p = people.get(i);
            int rank = 1;
            for ( int j = 0; j < people.size(); j++ ) {
                Person c = people.get(j);
                if ( c.w > p.w && c.h > p.h ) {
                    rank++;
                }
            }
            System.out.printf( "%d ", rank );
        }
    }
}
