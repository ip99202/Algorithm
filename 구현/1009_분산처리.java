import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

public class Main {

    public static int n, m, t;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        t = parseInt(st.nextToken());
        for (int k = 0; k < t; k++) {
            st = new StringTokenizer(br.readLine());
            n = parseInt(st.nextToken());
            m = parseInt(st.nextToken());
            if (n % 10 == 0)
                System.out.println(10);
            else {
                int b = (m - 1) % 4 + 1;
                System.out.println((int) Math.pow(n, b) % 10);
            }
        }
        br.close();
    }
}
