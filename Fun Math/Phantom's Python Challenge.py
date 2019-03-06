print"\n".join(`i`+" *"[[p.__setitem__(j,0)for j in p[i*i::i]]>0<p[i-2]|p[i+2]]for p in[range(input())]for i in p if i>1)
