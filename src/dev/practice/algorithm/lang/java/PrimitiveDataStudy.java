package dev.practice.algorithm.lang.java;

public class PrimitiveDataStudy {
    public static void main(String[] args) {
        // 숫자형

        // 1. 정수형 |=======================

        // short (2byte, -2^15 ~ 2^15)
        short a_short = 1;
        System.out.println(Short.MIN_VALUE);
        System.out.println(Short.MAX_VALUE);

        // int (4byte, -2^31 ~ 2^31)
        int a_int = 1;
        System.out.println(Integer.MIN_VALUE);
        System.out.println(Integer.MAX_VALUE);

        // long (8byte, -2^63 ~ 2^63)
        long a_long = 1L;
        System.out.println(Long.MIN_VALUE);
        System.out.println(Long.MAX_VALUE);

        // 2. 실수형 |=======================

        // float (가수부 23bit -> 소수점 이하 7자리까지)
        float a_float = 3.141592f;

        // double (가수부 52bit -> 소수점 이하 16자리까지)
        double a_double = 3.141592;

        // 3. 문자 |========================

        // char (1byte, 문자 1개)
        char a_char = 'a';

        // +) 문자열(string)은 원시타입이 아님 -> StringStudy class에서 설명
    }
}
