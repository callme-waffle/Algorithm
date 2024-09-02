package dev.practice.algorithm.lang.java;

public class LoopStudy {
    public static void main(String[] args) {
        // 반복문 (Loop Statements)

        // 1. for
        for ( int i = 0; i < 10; i++ ) {
            System.out.printf("[for] i is: %d\n", i);
        }

        // 2. for-each
        int[] nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        for ( int num: nums ) {
            System.out.printf("[foreach] num is: %d\n", num);
        }

        int i = 0;
        while( i < 10 ) {
            System.out.printf("[while] i is: %d\n", i++);
        }

        i = 0;
        do {
            System.out.printf("[do-while] i is: %d\n", i++);
        } while( i < 10 );
    }
}
