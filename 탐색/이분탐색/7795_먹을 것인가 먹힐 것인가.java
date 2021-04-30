import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;

public class Main {

    public static int t, n, m;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        t = Integer.parseInt(br.readLine());
        for (int k = 0; k < t; k++) {
            String input[] = br.readLine().split(" ");
            n = Integer.parseInt(input[0]);
            m = Integer.parseInt(input[1]);
            String n1[] = br.readLine().split(" ");
            String n2[] = br.readLine().split(" ");
            ArrayList<Integer> num1 = new ArrayList<Integer>();
            ArrayList<Integer> num2 = new ArrayList<Integer>();
            for (int i = 0; i < n; i++)
                num1.add(Integer.parseInt(n1[i]));
            for (int i = 0; i < m; i++)
                num2.add(Integer.parseInt(n2[i]));

            num1.sort(Comparator.reverseOrder());
            num2.sort(Comparator.reverseOrder());

            int tmp = 0, res = 0;
            for (int i = 0; i < n; i++) {
                if (num1.get(i) > num2.get(tmp)) {
                    res += (m - tmp);
                } else {
                    while (num1.get(i) <= num2.get(tmp)) {
                        tmp++;
                        if (tmp == m)
                            break;
                    }
                    res += (m - tmp);
                }
                if (tmp == m)
                    break;
            }

            sb.append(res + "\n");
        }
        System.out.println(sb);
    }
}
