import java.math.BigDecimal;
import java.util.Scanner;

public class j2166 {
    private static double getTriArea(double[] point1, double[] point2, double[] point3){
        return (point1[0] * point2[1] + point2[0] * point3[1] + point3[0] * point1[1] - point2[0] * point1[1] - point3[0] * point2[1] - point1[0] * point3[1])/2;
    }

    public static void main(String[] args) {
        int n;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        double[][] points = new double[n][2];

        for(int i = 0; i < n; i++){
            points[i][0] = scanner.nextDouble();
            points[i][1] = scanner.nextDouble();
        }

        int fixedPoint = 0;
        int[] remainPoint = new int[2];
        remainPoint[0] = 1;

        double sum = 0;
        for(remainPoint[1] = 2;remainPoint[1] < n; remainPoint[1] ++, remainPoint[0]++){
            sum += getTriArea(points[fixedPoint] , points[remainPoint[0]], points[remainPoint[1]]);
        }
        String res = BigDecimal.valueOf(Math.abs(sum)).toPlainString();
        if(res.charAt(res.length() - 2) != '.'){
            System.out.println(res +'.' + 0);
        }
        else{
            System.out.println(res);
        }
    }
}
