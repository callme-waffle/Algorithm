package algorithm.lang.java;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegexStudy {
    public static void main(String[] args) {
        // 정규식 (regular expressions; regex)

        // 1. 정규식 parsing (Pattern Class 사용)
        String regex_text = "/.*([0-9]{0,3}-[0-9]{4}-[0-9]{4})/";
        Pattern regex = Pattern.compile( regex_text );

        // 2. 문자열 내 일치형식 찾기 (Matcher Class 사용)
        String spl_test = "SPLIT_TEST_PLZ[010-1234-1234]";
        Matcher matcher = regex.matcher( spl_test );
        System.out.println( matcher.group() );
    }
}
