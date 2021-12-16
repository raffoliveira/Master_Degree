# Import packages
import numpy as np
import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt
import igraph as ig
import sys
sys.path.append(
    'C:\\Users\\rafae\\Documents\\Mestrado\\disciplinas\\Complex_networks\\Atividades\\Atividade_1\\')

# Load network

g = ig.Graph.Read_GML('karate.gml')

# Plot network

# creating labels
labels = np.arange(1, g.vcount()+1)
labels = [str(i) for i in labels]

# setting the new labels
# g.vs['label'] = labels

# plotting network
visual_style = {}
visual_style["vertex_size"] = [i for i in g.vs.degree()]
visual_style["vertex_color"] = ['gray' if i <
                                15 else 'blue' for i in g.vs.degree()]
visual_style["bbox"] = (400, 400)
visual_style["margin"] = 20
visual_style['vertex_shape'] = 'circle'
ig.plot(g, 'graph.pdf', ** visual_style)  # save the graph

# Get parameters

print(f'The network has: \n')
print(f'nodes -> {g.vcount()} ')
print(f'links -> {g.ecount()} edges')
print(f'maximum degree -> {g.vs.maxdegree()}')
print(f'minimum degree -> {min(g.vs.degree())} ')
print(f'average degree -> {int(sum(g.vs.degree())/g.vcount())} ')
print(f'maximum links -> {(g.vcount()*(g.vcount()-1))/2} ')
print(f'density -> {(sum(g.vs.degree()))/(g.vcount()*(g.vcount()-1)):.6} ')

# Degree distribuition

df = pd.DataFrame(data=g.vs.degree(), columns=['degree'])

sns.histplot(df['degree'], stat='probability')
plt.savefig('degree_dist_1.pdf', dpi=300)
plt.show()
sns.kdeplot(df['degree'])
plt.savefig('degree_dist_2.pdf', dpi=300)
plt.show()
