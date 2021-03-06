% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/DynComm.R
\docType{methods}
\name{communityNeighbours}
\alias{communityNeighbours}
\alias{DynComm.communityNeighbours}
\title{communityNeighbours(community)}
\usage{
DynComm.communityNeighbours(dyncomm,community)
}
\arguments{
\item{dyncomm}{A DynComm object, if not using the inline version of the 
function call}

\item{community}{The community to get neighbours from}
}
\value{
a matrix of all communities in the graph that are neighbours of the 
given community and their edge weight
}
\description{
Get all neighbours (communities connected through direct edges) of the given 
community in the graph from the selected post processing algorithm or the main 
algorithm, after the last iteration.
}
\details{
The return value is a matrix with two columns. The first is the neighbour and
the second is the weight of the edge that connects them.
}
\examples{
library(DynComm)

Parameters<-matrix(c("e","0.1","w", "FALSE"),ncol=2, byrow=TRUE)
dc<-DynComm(ALGORITHM$LOUVAIN,CRITERION$MODULARITY,Parameters)
dc$addRemoveEdges(
 matrix(
   c(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,12,13,1,1,1,2,2,2,18,12,19,20,2,3,11,12,4,9,5,9,22)
      ,ncol=2)
) 

dc$communities()
dc$communityNeighbours(12)

}
\seealso{
\code{\link{DynComm}} , \code{\link{postProcess}}
}
\author{
poltergeist0
}
