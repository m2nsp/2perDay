public class RaggedArray{
  public static void main(String[] args){
    int[][] ragged = new int[3][];
    ragged[0] = new int[1];
    ragged[1] = new int[2];
    ragged[2] = new int[3];

    for(int r=0; r<ragged.length; r++)
      for(int c = 0; c<ragged[r].length; c++)
        ragged[r][c] = c;

  }
}

  //ragged[0] -> [0]
  //ragged[1] -> [0, 1]
  //ragged[2] -> [0,1,2]
