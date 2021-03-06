/************************************************************************
 ************************* Developer Notice *****************************
 ************************************************************************
 * @details
 *
 * Aggregator class for all main algorithms implemented in C++11.
 *
 * All algorithms must be instantiated in the class defined in this file.
 *
 * When adding new algorithms, go through this file and implement modifications
 * as instructed by the markers (multi-line comments with dual row asterisks
 * before and after some text that starts with the word "TODO").
 *
 * Due to optimization, and to relief the programmer of new algorithms from
 * having to duplicate code, the functions used to add and remove edges are
 * split into two: the addRemoveEdgePre and addRemoveEdgePost which are used,
 * respectively, to process any data required before and after the edge is
 * added/removed from the graph.
 *
 * The arguments passed to both functions are the same, not just identical.
 *
 * Actually adding/removing the edge from the graph is performed automatically
 * between the call to addRemoveEdgePre and addRemoveEdgePost so the programmer
 * does not have to be concerned with it.
 *
 * The call to function run also occurs automatically but, this time, after the
 * last call to addRemoveEdgePost.
 *
 *
 * @author poltergeist0
 *
 * @date 2019-01-01
 ************************************************************************
 ************************************************************************
 ************************************************************************/

#ifndef SRC_ALGORITHM_H_
#define SRC_ALGORITHM_H_

#include "algorithmInterface.h"
#include "../criterion/criterion.h"
#include "../../algorithms/algorithmList.h"


/**
 * @brief Aggregator class for all main algorithms.
 *
 * @details
 *
 * It is a simple class that only instantiates all algorithms and dispatches
 * function calls to the correct one.
 *
 *
 * @author poltergeist0
 *
 * @date 2019-01-01
 */
class Algorithm: private AlgorithmBase{
private:
	/*
	 * algorithm selection. Can not be changed after initialization
	 */
	const ALGORITHM algrthm;

	/*
	 * Algorithms variables
	 */
	AlgorithmLouvain algorithmLouvain;
/* **********************************************************************
 ************************************************************************
 * TODO: Instantiate algorithm here. Give it a identical name to the class
 * but with lower case first letter
 ************************************************************************
 ************************************************************************/
//	Shaken algorithmShaken;

	/**
	 * Function to execute before adding or removing a single edge from the graph.
	 * It is used internally by the addRemoveEdges function.
	 * Useful if pre-processing is required, for example, to update some of
	 * variables before the edge can be added or removed.
	 * Any edge with a weight different from zero is inserted.
	 * Any edge with a weight of exactly zero is removed.
	 * Redirects call to algorithm variable.
	 *
	 * @param source source vertex
	 * @param destination destination vertex
	 * @param weight optional if adding an edge. Must be exactly zero to remove an edge.
	 * @return true if all operations succeeded. False, otherwise.
	 */
	bool addRemoveEdgePre(const typeVertex & source, const typeVertex & destination, const typeWeight & weight=1.0){
		switch(algrthm){
		default:
		case ALGORITHM::LOUVAIN:
			return algorithmLouvain.addRemoveEdgePre(source,destination,weight);
			break;
/* **********************************************************************
 ************************************************************************
 * TODO: Add algorithm call to addRemoveEdgePre
 ************************************************************************
 ************************************************************************/
//		case ALGORITHM::SHAKEN:
//			return louvain.addRemoveEdges(reader);
//		case ALGORITHM::
		}
	}

	/**
	 * Function execute after adding or removing a single edge from the graph.
	 * It is used internally by the addRemoveEdges function.
	 * Useful if post-processing is required, for example, to update some of
	 * variables after the edge has be added or removed.
	 * Any edge with a weight different from zero is inserted.
	 * Any edge with a weight of exactly zero is removed.
	 * Redirects call to algorithm variable.
	 *
	 * @param source source vertex
	 * @param destination destination vertex
	 * @param weight optional if adding an edge. Must be exactly zero to remove an edge.
	 * @return true if all operations succeeded. False, otherwise.
	 */
	bool addRemoveEdgePost(const typeVertex & source, const typeVertex & destination, const typeWeight & weight=1.0){
		switch(algrthm){
		default:
		case ALGORITHM::LOUVAIN:
			return algorithmLouvain.addRemoveEdgePost(source,destination,weight);
		break;
/* **********************************************************************
 ************************************************************************
 * TODO: Add algorithm call to addRemoveEdgePost
 ************************************************************************
 ************************************************************************/
		//		case ALGORITHM::SHAKEN:
		//			return louvain.addRemoveEdges(reader);
		//		case ALGORITHM::
		}
	}

	/**
	 * Function where the actual algorithms are implemented.
	 * It is called at the end of the addRemoveEdges function.
	 * Redirects call to algorithm variable.
	 *
	 * @return true if all operations succeeded. False, otherwise.
	 */
	bool run(){
		switch(algrthm){
		default:
		case ALGORITHM::LOUVAIN:
			return algorithmLouvain.run();
			break;
/* **********************************************************************
 ************************************************************************
 * TODO: Add algorithm call to run
 ************************************************************************
 ************************************************************************/
		//		case ALGORITHM::SHAKEN:
		//			return louvain.addRemoveEdges(reader);
		//		case ALGORITHM::
		}
	}

public:
	/**
	 * Default constructor not acceptable.
	 * Must be passed at least the chosen algorithm and the graph
	 */
	Algorithm()=delete;

	/**
	 * Constructor.
	 *
	 * @param graph reference to the graph object
	 * @param quality reference to the quality object
	 * @param algorithmParameters reference to the parameters object
	 */
	Algorithm(
			GraphUndirectedGroupable & grph
			,Criterion & quality
			, ALGORITHM algorithm=ALGORITHM::LOUVAIN
			, ProgramParameters & algorithmParameters=argumentsDefault
	)
	:
		AlgorithmBase(grph,quality,algorithmParameters)
		,algrthm(algorithm)
		//initialize all algorithms. Only the one passed a reader instead of a dummy reader will work
		,algorithmLouvain(grph,quality,algorithmParameters)
/* **********************************************************************
 ************************************************************************
 * TODO: Initialize algorithm variable here
 ************************************************************************
 ************************************************************************/
	{
	}

	/**
	 * Function to add and remove edges from the graph.
	 * Any edge with a weight different from zero is inserted.
	 * Any edge with a weight of exactly zero is removed.
	 *
	 * @param reader is a Reader object that is responsible for converting the required data from its original format to Edges
	 * @return true if adding/removing succeeded
	 */
	bool addRemoveEdges(ReaderInterface<Edge> * reader){
		dbg.pre(DEBUG_LEVEL::MODIFICATIONS,"Aa", debugPrint());
		//TODO add reader error handling
		ReaderInterface<Edge>::NEXTTYPE n=reader->hasNext();
//		if(n==ReaderInterface<Edge>::NEXTTYPE::CANNOTOPEN) return false;
		while(n!=ReaderInterface<Edge>::NEXTTYPE::CANNOTOPEN && n!=ReaderInterface<Edge>::NEXTTYPE::ENDOFFILE){
			if(n==ReaderInterface<Edge>::NEXTTYPE::VALUE){
				Edge ed=reader->next();
				dbg.msg(DEBUG_LEVEL::CALLS, "e"+ed.debugPrint());
				addRemoveEdgePre(ed.source(),ed.destination(),ed.weight());
				if(ed.weight()==0){
//					dbg.msg(DEBUG_LEVEL::ACTIONS, "a");
					grph.removeEdge(ed);
				}
				else{
//					dbg.msg(DEBUG_LEVEL::ACTIONS, "r");
					grph.addEdge(ed,true);
				}
				addRemoveEdgePost(ed.source(),ed.destination(),ed.weight());
			}
			else{
				reader->next();//skip anything else other than a value
			}
			n=reader->hasNext();
		}
		bool b=false;
		if(n!=ReaderInterface<Edge>::NEXTTYPE::CANNOTOPEN){
			if(reader->lineCounter()>0) b=run();
			else b=true;//succeed if the file is empty
		}
		dbg.msg(DEBUG_LEVEL::CALLS, "r"+std::to_string(b));
		dbg.post(DEBUG_LEVEL::MODIFICATIONS,debugPrint());
		return b;
	}

	/**
	 * Function that converts this object to a string representation.
	 * Might be useful for debugging.
	 *
	 * @param sf is a StringFormater object that facilitates formating
	 * @return the string representing this object
	 */
	  const std::string toString(const StringFormatter & sf=defaultStringFormatter)const{
			switch(algrthm){
			default:
			case ALGORITHM::LOUVAIN:
				return algorithmLouvain.toString(sf);
			break;
/* **********************************************************************
 ************************************************************************
 * TODO: Add algorithm call to toString
 ************************************************************************
 ************************************************************************/
			//		case ALGORITHM::SHAKEN:
			//			return louvain.addRemoveEdges(reader);
			//		case ALGORITHM::
			}
	  }

	const std::string debugPrint()const {
//		std::stringstream ss;
		switch(algrthm){
		default:
		case ALGORITHM::LOUVAIN:
			return algorithmLouvain.debugPrint();
		break;
/* **********************************************************************
************************************************************************
* TODO: Add algorithm call to toString
************************************************************************
************************************************************************/
		//		case ALGORITHM::SHAKEN:
		//			return louvain.addRemoveEdges(reader);
		//		case ALGORITHM::
		}
//		return ss.str();
	}

};

#endif /* SRC_ALGORITHM_H_ */
