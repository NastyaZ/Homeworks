//Зотова А., 171 гр
type 't tree =
  | Node of int * 't tree * 't tree
  | Nil

let rec spaces n = 
  match n with
  |0 -> printf " "
  |n -> printf " "
        spaces (n-1)

let rec LCR t h =
  match t with
  |Node(x, L, R) ->LCR L (h+1)
                   spaces h
                   printf "%d\n" x
                   LCR R (h+1)
  |Nil -> ()

let rec LRC t h =
  match t with
  |Node(x, L, R) ->LRC L (h+1)
                   LRC R (h+1)
                   spaces h
                   printf "%d\n" x
  |Nil -> ()

let rec CLR t h =
  match t with
  |Node(x, L, R) -> spaces h
                    printf "%d\n" x
                    CLR L (h+1)
                    CLR R (h+1)
  |Nil -> ()

let rec insert x t =  
  match t with
  |Nil -> Node(x,Nil,Nil)  
  | Node(z,L,R) -> if z=x then t                   
                   else if x<z then Node(z,insert x L,R)        
                   else Node(z,L,insert x R)

let rec one t=
  match t with
  |Nil -> 0
  |Node(x, Nil, R)-> x
  |Node(x, L, R)-> one L 
                     
let rec delete x t =  
  match t with
  |Nil -> Nil  
  | Node(z,L,R) -> if x<z then Node(z,delete x L,R)        
                   else if x>z then Node(z,L, delete x R)
                   else 
                     match L, R with
                     |Nil, Nil -> Nil
                     |Node(z1, L1, R1), Nil -> Node(z1, L1, R1)
                     |Nil, Node(z2, L2, R2) -> Node(z2, L2, R2)
                     |L, Node (z2, Nil, R2)-> Node(z2, L, R2)
                     |L, Node(z2, L2, R2) ->
                       let o = one L2
                       Node (o, L, delete o (Node(z2, L2, R2)))

[<EntryPoint>]
let main argv = 
  let t=Nil
  let t = insert 4 t
  let t = insert 2 t
  let t = insert 3 t
  let t = insert 0 t
  let t = insert 7 t
  let t = insert 11 t   
  let t = insert 5 t
  let t = delete 4 t
  let h=0
  printf "LCR\n"
  printf "%A\n", LCR t h
  let h = 0
  printf "CLR\n"
  printf "%A\n", CLR t h
  let h=0
  printf "LRC\n"
  printf "%A\n", LRC t h
  0
