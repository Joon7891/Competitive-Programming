print"\n".join(`i`+" *"[[p.__setitem__(j,0)for j in range(i*i,len(p),i)]>0<p[i+2]|p[i-2]]for p in[range(input())]for i in range(2,len(p)) if p[i])
