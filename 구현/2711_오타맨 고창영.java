import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

public class Main {

    public static int n, t;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        t = parseInt(st.nextToken());
        for (int k = 0; k < t; k++) {
            st = new StringTokenizer(br.readLine());
            n = parseInt(st.nextToken());
            String spell = st.nextToken();
            StringBuilder sb = new StringBuilder(spell);
            System.out.println(sb.deleteCharAt(n - 1));
        }
        br.close();
    }
}
