import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static int n, m;
    public static Queue<Integer> q = new LinkedList<>();
    public static ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
    public static int[] indegree;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        indegree = new int[n + 1];

        for (int i = 0; i <= n; i++)
            arr.add(new ArrayList<Integer>());
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            arr.get(x).add(y);
            indegree[y]++;
        }

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0)
                q.add(i);
        }
        while (!q.isEmpty()) {
            int now = q.poll();
            System.out.print(now + " ");
            for (int i = 0; i < arr.get(now).size(); i++) {
                int next = arr.get(now).get(i);
                indegree[next]--;
                if (indegree[next] == 0)
                    q.add(next);
            }
        }
        br.close();
    }
}
