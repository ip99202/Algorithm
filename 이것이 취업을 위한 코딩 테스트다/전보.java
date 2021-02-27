import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class City implements Comparable<City> {
    private int num;
    private int cost;

    public City(int num, int cost) {
        this.num = num;
        this.cost = cost;
    }

    public int getNum() {
        return num;
    }

    public int getCost() {
        return cost;
    }

    @Override
    public int compareTo(City o) {
        if (this.cost < o.cost)
            return -1;
        return 1;
    }
}

public class Main {

    public static int n, m, c;
    public static ArrayList<ArrayList<City>> arr = new ArrayList<ArrayList<City>>();
    public static PriorityQueue<City> pq = new PriorityQueue<City>();
    public static int[] res;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        res = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            res[i] = (int) 1e9;
            arr.add(new ArrayList<City>());
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            arr.get(a).add(new City(b, c));
        }

        pq.add(new City(c, 0));
        res[c] = 0;
        while (!pq.isEmpty()) {
            City city = pq.poll();
            int now = city.getNum();
            int cost = city.getCost();
            if(res[now] < cost)
                continue;
            for (int i = 0; i < arr.get(now).size(); i++) {
                int next = arr.get(now).get(i).getNum();
                int nCost = arr.get(now).get(i).getCost();
                if (nCost < res[next]) {
                    res[next] = nCost;
                    pq.add(new City(next, nCost));
                }
            }
        }
        int cnt = 0, cost = 0;
        for (int i = 1; i <= n; i++) {
            if (res[i] < (int) 1e9) {
                cnt++;
                cost = Math.max(cost, res[i]);
            }
        }
        System.out.println(cnt - 1 + " " + cost);
        br.close();
    }
}
