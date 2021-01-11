import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

class Pair {
    int x, s;

    public Pair(int x, int s) {
        this.x = x;
        this.s = s;
    }
}

public class Main {

    public static int n;
    public static ArrayList<Pair> arr = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            arr.add(new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        arr.sort(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if (o1.x > o2.x)
                    return 1;
                else return -1;
            }
        });

        int R = Integer.MAX_VALUE;
        for (int i = 1; i < n; i++) {
            Pair now = arr.get(i - 1);
            Pair next = arr.get(i);
            if (now.s == 0 || next.s == 0) {
                if (now.s == 0 && next.s == 0)
                    continue;
                R = Math.min(next.x - now.x, R);
            }
        }
        R--;

        int res = 1;
        for (int i = 1; i < n; i++) {
            Pair now = arr.get(i - 1);
            Pair next = arr.get(i);
            if (next.x - now.x > R && next.s == 1) {
                res++;
            }
        }
        System.out.println(res);
        br.close();
    }
}