/*
 * modularity.h
 *
 *  Created on: 20/08/2018
 *      Author: poltergeist0
 */

#ifndef QUALITYMODULARITY_H_
#define QUALITYMODULARITY_H_

#include "qualityBase.h"

class Modularity: public QualityBase{
public:

	/**
	 * Constructor
	 * @param graph
	 * @param parameters
	 */
	Modularity(GraphUndirectedGroupable & graph,const ProgramParameters & parameters=argumentsDefault):QualityBase(graph,parameters) {}

	/**
	 * Destructor
	 */
	~Modularity(){}


	typeQuality gain(const typeNode & node,const typeCommunity & comm)const{
		//TODO review the formulas
		const typeWeight & w_degree=g.weighted_degree(node);
		const typeCommunity & oc=g.community(node);
//		std::map<typeCommunity,typeWeight>::const_iterator it=tot.find(comm);
//		typeWeight totc=it->second;
		typeWeight totc = g.totalEdges(comm);
		if(comm==oc){
//			std::map<typeCommunity,typeWeight>::const_iterator ito=tot.find(dlt.getOriginalCommunity());
//			const typeWeight toto = ito->second;
//			totc=toto-dlt.getOriginalTotalEdges();
//			totc=totc-dlt.getOriginalTotalEdges();
			totc=totc-g.weighted_degree(node);
		}
//		else{
//			std::map<typeCommunity,typeWeight>::const_iterator it=tot.find(comm);
//			totc=it->second;
//		}
		const typeWeight & m2   = 2*g.totalWeight();
		return (g.neighborsCommunityWeight(node,comm) - totc*w_degree/m2);
	}

	typeQuality quality()const{
		//TODO review the formulas
		typeWeight q  = 0.0L;
		const typeWeight & m2 = 2*g.totalWeight();
		for (typeNodeListIterator it=g.getNodes().begin() ; it!=g.getNodes().end() ; it++){
			const typeNode & i=*it;
//			std::map<typeCommunity,typeWeight>::const_iterator itt=in.find(i);
//			const typeWeight & a = itt->second;
			const typeWeight & a = g.innerEdges(i);
//			itt=tot.find(i);
//			const typeWeight & t = itt->second;
			const typeWeight & t = g.totalEdges(i);
			if (t > 0.0L) q += a - (t*t) / m2;
		}
		q /= m2;
		return q;
	}

};

#endif /* QUALITYMODULARITY_H_ */
