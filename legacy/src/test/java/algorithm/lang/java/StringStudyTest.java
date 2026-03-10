package algorithm.lang.java;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class StringStudyTest {

    private String rep_test = "";

    @BeforeEach
    public void setTestSentence() {
        this.rep_test = "REPLACE_TEXT_PLZ[ABCDEFG-ABCDEFG-ABCDEFG-ABCDEFG]";
    }

    @Test
    public void replaceTest() {
        String test_res = rep_test.replace("ABCDEFG", "[CHANGED:D]");
        String pred_res = "REPLACE_TEXT_PLZ[[CHANGED:D]-ABCDEFG-ABCDEFG-ABCDEFG]";
        Assertions.assertEquals( pred_res, test_res );
    }

    @Test
    public void replaceFirstTest() {
        String test_res = rep_test.replaceFirst("ABCDEFG", "[CHANGED:D]");
        String pred_res = "REPLACE_TEXT_PLZ[[CHANGED:D]-ABCDEFG-ABCDEFG-ABCDEFG]";
        Assertions.assertEquals( pred_res, test_res );
    }

    @Test
    public void replaceAllTest() {
        String test_res = rep_test.replaceAll("ABCDEFG", "[CHANGED:D]");
        String pred_res = "REPLACE_TEXT_PLZ[[CHANGED:D]-[CHANGED:D]-[CHANGED:D]-[CHANGED:D]]";
        Assertions.assertEquals( pred_res, test_res );
    }
}