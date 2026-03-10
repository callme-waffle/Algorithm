package algorithm.lang.java.VersionStudy.Java17.SealedStudy;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter @Setter
@AllArgsConstructor @NoArgsConstructor
public sealed class UndergraduatedStudent
    permits CourseA, CourseB
{
    private String name;
    private Long sid;
    private int joinStatus;

    public final int getGraduationCredit() {
        return 148;
    }

    public final int getEnrollmentFee() {
        // logics...
        return 4430000;
    }
}

