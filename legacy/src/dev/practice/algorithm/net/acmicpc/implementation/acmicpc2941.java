package algorithm.net.acmicpc.implementation;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class acmicpc2941 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner( System.in );
        String str = scanner.nextLine();

        int cnt = 0;

        Pattern pattern = Pattern.compile( "(c=|c-|dz=|d-|lj|nj|s=|z=)" );
        Matcher matcher = pattern.matcher( str );

        while( matcher.find() ) cnt++;

        System.out.println( cnt + matcher.replaceAll( "" ).length() );
    }
}
