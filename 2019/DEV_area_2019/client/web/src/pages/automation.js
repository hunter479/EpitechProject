import React from 'react';

import Layout from "../components/layout"
import SEO from "../components/seo"

// import { makeStyles } from '@material-ui/core/styles';
// import Paper from '@material-ui/core/Paper';
// import Grid from '@material-ui/core/Grid';
// import GridItem from './GridItem';

export default ({location}) => {

    return (
        <Layout>
            <SEO title="Home 2" />
            <p>yo its {location.state.id}</p>
        </Layout>
    )
}
