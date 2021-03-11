import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int p1, p2, p3, x1, x2, x3;
        p1 = Integer.parseInt(st.nextToken());
        p2 = Integer.parseInt(st.nextToken());
        p3 = Integer.parseInt(st.nextToken());
        x1 = Integer.parseInt(st.nextToken());
        x2 = Integer.parseInt(st.nextToken());
        x3 = Integer.parseInt(st.nextToken());

        for (int n = 1; n <= p1 * p2 * p3; n++) {
            if (n % p1 == x1 && n % p2 == x2 && n % p3 == x3) {
                System.out.println(n);
                System.exit(0);
            }
        }
        System.out.println(-1);
        br.close();
    }
}