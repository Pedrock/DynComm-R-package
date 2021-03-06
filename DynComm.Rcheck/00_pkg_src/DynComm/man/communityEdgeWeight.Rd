% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/DynComm.R
\docType{methods}
\name{communityEdgeWeight}
\alias{communityEdgeWeight}
\alias{DynComm.communityEdgeWeight}
\title{communityEdgeWeight(source,destination)}
\usage{
DynComm.communityEdgeWeight(dyncomm,source,destination)
}
\arguments{
\item{dyncomm}{A DynComm object, if not using the inline version of the 
function call}

\item{source}{The name of the source community that is part of the edge}

\item{destination}{The name of the destination community that is part of the 
edge}
}
\value{
a floating point number with the weight
}
\description{
Get the weight of the edge that goes from source community to destination 
community from the selected post processing algorithm or the main algorithm, 
after the last iteration.
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
dc$communityEdgeWeight(0,12)

}
\seealso{
\code{\link{DynComm}} , \code{\link{postProcess}}
}
\author{
poltergeist0
}
